# 选课系统 SQL

## 关系模型

学生表 Student(Sno,Sname,Sage,Ssex)

教师表 Teacher(Tno,Tname)

课程表 Course(Cno,Cname,Tno)

学生成绩表 SC(Sno,Cno,Score)

## 数据定义

```sql
--表（一）Student (学生表)
CREATE TABLE Student
( Sno CHAR(3) PRIMARY KEY,
Sname CHAR(8),
Ssex CHAR(2),
Sage DATE
)

--表（二）Course（课程表）
CREATE TABLE Course
( Cno CHAR(5) PRIMARY KEY,
Cname VARCHAR(10),
Tno CHAR(3),
FOREIGN KEY (Tno) REFERENCES Teacher(Tno)
)
--表（三）Score(成绩表)
CREATE TABLE SC
( Sno CHAR(3),
Cno CHAR(5),
Score decimal(4,1),
PRIMARY KEY (Sno,Cno),
FOREIGN KEY (Sno) REFERENCES Student(Sno),
FOREIGN KEY (Cno)REFERENCES Course(Cno)

)
--表（四）Teacher(教师表)
CREATE TABLE Teacher
( Tno CHAR(3) PRIMARY KEY,
Tname CHAR(8),
)
```

```sql
select 2019 - sage as age ,sage as birth,2019 as now from teacher where tno = 't01'

select * from sc where cno = 'c01' and score not between 60 and 75
-- score >= 60 and score <=75

select * from sc --where cno = 'c01' --and score not between 60 and 75
order by sno asc, score desc
李老师

每个学生的选课数量 sno, count
select sno, count(distinct cno)
from sc
group by sno

所有课的数量
select count(*) from course

学了全部课程的学生的学号

select Sname from studentf

where Sno IN

(select Sno from SC

group by Sno //根据Sno分组，统计每个学生选修了几门课程。如果等于course的总数，就是我们要找的Sno

having count(*) = (select count(*) from course ))    //统计course中共有几门课程

学了程序设计或数据库的学生的学号

查询没有被选过的课程
select *
from course
where not exists (select * from sc where course.cno = cno)

查询s06没选的课
select *
from course
where not exists (select * from sc where sno = 's06' and course.cno = cno)

查询选了所有课的学生
select *
from student
where not exists(
select *
from course
where not exists (select * from sc where student.sno = sno and course.cno = cno)
)

查询一门没学的学生
select *
from student
where not exists (select * from sc where student.sno = sno)

查询学了至少一门的学生
select *
from student
where exists (select * from sc where student.sno = sno)

查询和s05学习同一门课的学生学号
select *
from student,sc
where cno in (select cno from sc where sno = 's05')
and student.sno = sc.sno

查询小二学了哪门课

查询和s02学习的课完全相同的学生

SELECT Sno
   FROM SC
   WHERE Cno IN ( SELECT Cno
   FROM SC
   WHERE Sno = '1002' )
   GROUP BY Sno
   HAVING COUNT(*) = ( SELECT COUNT(*)
   FROM SC
   WHERE Sno = '1002'
   )

SELECT *
FROM student
WHERE NOT exists
    (SELECT *
     FROM
       (SELECT cno
        FROM sc
        WHERE sno = 's02') AS selected
     WHERE NOT EXISTS
         (SELECT *
          FROM sc
          WHERE sno = student.sno
            AND cno = selected.cno) )
  AND NOT EXISTS
    (SELECT *
     FROM
       (SELECT *
        FROM course
        WHERE NOT EXISTS
            (SELECT *
             FROM sc
             WHERE sno = 's02'
               AND cno = course.cno)) AS unselected
     WHERE EXISTS
         (SELECT *
          FROM sc
          WHERE sno= student.sno
            AND cno= unselected.cno ) )

查询选了c01这门课的学生
select *
from student
where exists (select * from sc where student.sno = sno and cno = 'c01')
-- and exists (select * from sc where student.sno = sno and cno = 'c02')
```

## 数据查询

1. 查询“001”课程比“002”课程成绩高的所有学生的学号;

   ```sql

   SELECT a.Sno
   FROM ( SELECT *
   FROM dbo.SC
   WHERE Cno = '001'
   ) a
   INNER JOIN ( SELECT *
   FROM dbo.SC
   WHERE Cno = '002'
   ) b ON a.Sno = b.Sno
   WHERE a.Score > b.Score

   ```

1. 查询平均成绩大于 60 分的同学的学号和平均成绩;

   ```sql

   SELECT Sno ,
   AVG(Score)
   FROM dbo.SC
   GROUP BY Sno
   HAVING AVG(Score) > 60

   ```

1. 查询所有同学的学号、姓名、选课数、总成绩;

   ```sql

   SELECT a.Sno ,
   a.Sname ,
   COUNT(b.Cno) ,
   SUM(b.Score)
   FROM dbo.Student a
   LEFT OUTER JOIN dbo.SC b ON a.Sno = b.Sno
   GROUP BY a.Sno ,
   a.Sname

   ```

1. 查询姓“李”的老师的个数;

   ```sql

   SELECT COUNT(Tno)
   FROM dbo.Teacher
   WHERE Tname LIKE '李%'

   ```

1. 查询没学过“张老师”老师课的同学的学号、姓名;

   ```sql

   SELECT Student.Sno ,
   Student.Sname
   FROM Student
   WHERE Sno NOT IN ( SELECT DISTINCT
   ( SC.Sno )
   FROM SC ,
   Course ,
   Teacher
   WHERE SC.Cno = Course.Cno
   AND Teacher.Tno = Course.Tno
   AND Teacher.Tname = '张老师' )

   ```

1. 查询学过“001”并且也学过编号“002”课程的同学的学号、姓名;

   ```sql

   SELECT Student.Sno ,
   Student.Sname
   FROM Student ,
   SC
   WHERE Student.Sno = SC.Sno
   AND SC.Cno = '001'
   AND EXISTS ( SELECT
   FROM SC AS SC_2
   WHERE SC_2.Sno = SC.Sno
   AND SC_2.Cno = '002' )

   ```

1. 查询学过“张老师”老师所教的所有课的同学的学号、姓名;

   ```sql

   SELECT Sno ,
   Sname
   FROM Student
   WHERE Sno IN ( SELECT Sno
   FROM SC ,
   Course ,
   Teacher
   WHERE SC.Cno = Course.Cno
   AND Teacher.Tno = Course.Tno
   AND Teacher.Tname = '张老师'
   GROUP BY Sno
   HAVING COUNT(SC.Cno) = ( SELECT COUNT(Cno)
   FROM Course ,
   Teacher
   WHERE Teacher.Tno = Course.Tno
   AND Tname = '张老师'
   ) )

   ```

1. 查询课程编号“002”的成绩比课程编号“001”课程低的所有同学的学号、姓名;

   ```sql

   SELECT Sno ,
   Sname
   FROM ( SELECT Student.Sno ,
   Student.Sname ,
   Score ,
   ( SELECT Score
   FROM SC SC_2
   WHERE SC_2.Sno = Student.Sno
   AND SC_2.Cno = '002'
   ) Score2
   FROM Student ,
   SC
   WHERE Student.Sno = SC.Sno
   AND Cno = '001'
   ) S_2
   WHERE Score2 < Score
   ```

1. 查询所有课程成绩小于 60 分的同学的学号、姓名;

   ```sql

   SELECT Sno ,
   Sname
   FROM Student
   WHERE Sno NOT IN ( SELECT Student.Sno
   FROM Student ,
   SC
   WHERE Student.Sno = SC.Sno
   AND Score > 60 )
   ```

1. 查询没有学全所有课的同学的学号、姓名;

   ```sql

   SELECT Student.Sno ,
   Student.Sname
   FROM Student ,
   SC
   WHERE Student.Sno = SC.Sno
   GROUP BY Student.Sno ,
   Student.Sname
   HAVING COUNT(Cno) < ( SELECT COUNT(Cno)
   FROM Course
   )

   ```

1. 查询至少有一门课与学号为“1001”的同学所学相同的同学的学号和姓名;

   ```sql

   SELECT Sno ,
   Sname
   FROM Student ,
   SC
   WHERE Student.Sno = SC.Sno
   AND Cno IN ( SELECT Cno
   FROM SC
   WHERE Sno = '1001' )

   ```

1. 查询和“1002”号的同学学习的课程完全相同的其他同学学号和姓名;

   ```sql

   SELECT Sno
   FROM SC
   WHERE Cno IN ( SELECT Cno
   FROM SC
   WHERE Sno = '1002' )
   GROUP BY Sno
   HAVING COUNT(*) = ( SELECT COUNT(*)
   FROM SC
   WHERE Sno = '1002'
   )

   ```

1. 按平均成绩从高到低显示所有学生的“数据库”、“企业管理”、“英语”三门的课程成绩，按如下形式显示： 学生 ID,数据库,企业管理,英语,有效课程数,有效平均分

   ```sql

   SELECT Sno AS 学生 ID ,
   ( SELECT Score
   FROM SC
   WHERE SC.Sno = t.Sno
   AND Cno = '004'
   ) AS 数据库 ,
   ( SELECT Score
   FROM SC
   WHERE SC.Sno = t.Sno
   AND Cno = '001'
   ) AS 企业管理 ,
   ( SELECT Score
   FROM SC
   WHERE SC.Sno = t.Sno
   AND Cno = '006'
   ) AS 英语 ,
   COUNT(*) AS 有效课程数 ,
   AVG(t.Score) AS 平均成绩
   FROM SC AS t
   GROUP BY Sno
   ORDER BY AVG(t.Score)

   ```

1. 查询各科成绩最高和最低的分：以如下形式显示：课程 ID，最高分，最低分

   ```sql

   SELECT L.Cno AS 课程 ID ,
   L.Score AS 最高分 ,
   R.Score AS 最低分
   FROM SC L ,
   SC AS R
   WHERE L.Cno = R.Cno
   AND L.Score = ( SELECT MAX(IL.Score)
   FROM SC AS IL ,
   Student AS IM
   WHERE L.Cno = IL.Cno
   AND IM.Sno = IL.Sno
   GROUP BY IL.Cno
   )
   AND R.Score = ( SELECT MIN(IR.Score)
   FROM SC AS IR
   WHERE R.Cno = IR.Cno
   GROUP BY IR.Cno
   )

   ```

1. 按各科平均成绩从低到高和及格率的百分数从高到低顺序

   ```sql

   SELECT t.Cno AS 课程号 ,
   MAX(course.Cname) AS 课程名 ,
   ISNULL(AVG(Score), 0) AS 平均成绩 ,
   100 * SUM(CASE WHEN ISNULL(Score, 0) >= 60 THEN 1
   ELSE 0
   END) / COUNT(*) AS 及格百分数
   FROM SC T ,
   Course
   WHERE t.Cno = course.Cno
   GROUP BY t.Cno
   ORDER BY 100 * SUM(CASE WHEN ISNULL(Score, 0) >= 60 THEN 1
   ELSE 0
   END) / COUNT(*) DESC

   ```

1. 查询如下课程平均成绩和及格率的百分数(用"1 行"显示): 企业管理（001），马克思（002），OO&UML （003），数据库（004）

   ```sql

   SELECT SUM(CASE WHEN Cno ='001' THEN Score ELSE 0 END)/SUM(CASE Cno WHEN '001' THEN 1 ELSE 0 END) AS 企业管理平均分
   ,100 * SUM(CASE WHEN Cno = '001' AND Score >= 60 THEN 1 ELSE 0 END)/SUM(CASE WHEN Cno = '001' THEN 1 ELSE 0 END) AS 企业管理及格百分数
   ,SUM(CASE WHEN Cno = '002' THEN Score ELSE 0 END)/SUM(CASE Cno WHEN '002' THEN 1 ELSE 0 END) AS 马克思平均分
   ,100 * SUM(CASE WHEN Cno = '002' AND Score >= 60 THEN 1 ELSE 0 END)/SUM(CASE WHEN Cno = '002' THEN 1 ELSE 0 END) AS 马克思及格百分数
   ,SUM(CASE WHEN Cno = '003' THEN Score ELSE 0 END)/SUM(CASE Cno WHEN '003' THEN 1 ELSE 0 END) AS UML 平均分
   ,100 * SUM(CASE WHEN Cno = '003' AND Score >= 60 THEN 1 ELSE 0 END)/SUM(CASE WHEN Cno = '003' THEN 1 ELSE 0 END) AS UML 及格百分数
   ,SUM(CASE WHEN Cno = '004' THEN Score ELSE 0 END)/SUM(CASE Cno WHEN '004' THEN 1 ELSE 0 END) AS 数据库平均分
   ,100 * SUM(CASE WHEN Cno = '004' AND Score >= 60 THEN 1 ELSE 0 END)/SUM(CASE WHEN Cno = '004' THEN 1 ELSE 0 END) AS 数据库及格百分数
   FROM SC

   ```

1. 查询不同老师所教不同课程平均分从高到低显示

   ```sql

   SELECT max(Z.Tno) AS 教师 ID,MAX(Z.Tname) AS 教师姓名,C.Cno AS 课程ＩＤ,MAX(C.Cname) AS 课程名称,AVG(Score) AS 平均成绩
   FROM SC AS T,Course AS C ,Teacher AS Z
   WHERE T.Cno=C.Cno AND C.Tno=Z.Tno
   GROUP BY C.Cno
   ORDER BY AVG(Score) DESC

   ```

1. 统计列印各科成绩,各分数段人数:课程 ID,课程名称,[100-85],[85-70],[70-60],[ <60]

   ```sql

   SELECT SC.Cno AS 课程 ID, Cname AS 课程名称
   ,SUM(CASE WHEN Score BETWEEN 85 AND 100 THEN 1 ELSE 0 END) AS [100 - 85]
   ,SUM(CASE WHEN Score BETWEEN 70 AND 85 THEN 1 ELSE 0 END) AS [85 - 70]
   ,SUM(CASE WHEN Score BETWEEN 60 AND 70 THEN 1 ELSE 0 END) AS [70 - 60]
   ,SUM(CASE WHEN Score < 60 THEN 1 ELSE 0 END) AS [60 -]
   FROM SC,Course
   WHERE SC.Cno=Course.Cno
   GROUP BY SC.Cno,Cname

   ```

1. 查询学生平均成绩及其名次

   ```sql

   SELECT 1+(SELECT COUNT( DISTINCT 平均成绩)
   FROM (SELECT Sno,AVG(Score) AS 平均成绩
   FROM SC
   GROUP BY Sno
   ) AS T1
   WHERE 平均成绩 > T2.平均成绩) AS 名次,
   Sno AS 学生学号,平均成绩
   FROM (SELECT Sno,AVG(Score) 平均成绩
   FROM SC
   GROUP BY Sno
   ) AS T2
   ORDER BY 平均成绩 desc

   ```

1. 查询各科成绩前三名的记录:(不考虑成绩并列情况)

   ```sql

   SELECT t1.Sno AS 学生 ID,t1.Cno AS 课程 ID,Score AS 分数
   FROM SC t1
   WHERE Score IN (SELECT TOP 3 Score
   FROM SC
   WHERE t1.Cno= Cno
   ORDER BY Score DESC
   )
   ORDER BY t1.Cno;

   ```

1. 查询每门课程被选修的学生数

   ```sql

   SELECT Cno,COUNT(Sno) FROM sc GROUP BY Cno;

   ```

1. 查询出只选修了一门课程的全部学生的学号和姓名

   ```sql
    SELECT SC.Sno,Student.Sname,COUNT(Cno) AS 选课数
    FROM SC ,Student
    WHERE SC.Sno=Student.Sno GROUP BY SC.Sno ,Student.Sname HAVING COUNT(Cno)=1;
   ```

1. 查询男生、女生人数

   ```sql
   SELECT COUNT(Ssex) AS 男生人数 FROM Student GROUP BY Ssex HAVING Ssex='男';
   SELECT COUNT(Ssex) AS 女生人数 FROM Student GROUP BY Ssex HAVING Ssex='女';
   ```

1. 查询姓“张”的学生名单

   ```sql
   SELECT Sname FROM Student WHERE Sname like '张%';
   ```

1. 查询同名同性学生名单，并统计同名人数

   ```sql
   SELECT Sname,COUNT(*) FROM Student GROUP BY Sname HAVING COUNT(*)>1;
   ```

1. 1981 年出生的学生名单(注：Student 表中 Sage 列的类型是 date)

   ```sql
   SELECT Sname, CONVERT(CHAR (11),DATEPART(year,Sage)) AS age
   FROM student
   WHERE CONVERT(CHAR(11),DATEPART(year,Sage))='1981';
   ```

1. 查询每门课程的平均成绩，结果按平均成绩升序排列，平均成绩相同时，按课程号降序排列

   ```sql
   SELECT Cno,Avg(Score) FROM SC GROUP BY Cno ORDER BY Avg(Score),Cno DESC ;
   ```

1. 查询平均成绩大于 85 的所有学生的学号、姓名和平均成绩

   ```sql
   SELECT Sname,SC.Sno ,avg(Score)
   FROM Student,SC
   WHERE Student.Sno=SC.Sno GROUP BY SC.Sno,Sname HAVING avg(Score)>85;
   ```

1. 查询课程名称为“数据库”，且分数低于 60 的学生姓名和分数

   ```sql
   SELECT Sname,isnull(Score,0)
   FROM Student,SC,Course
   WHERE SC.Sno=Student.Sno AND SC.Cno=Course.Cno AND Course.Cname='数据库'AND Score <60;
   ```

1. 查询所有学生的选课情况;

   ```sql
   SELECT SC.Sno,SC.Cno,Sname,Cname
   FROM SC,Student,Course
   WHERE SC.Sno=Student.Sno AND SC.Cno=Course.Cno ;
   ```

1. 查询任何一门课程成绩在 70 分以上的姓名、课程名称和分数;

   ```sql
   SELECT DISTINCT student.Sno,student.Sname,SC.Cno,SC.Score
   FROM student,Sc
   WHERE SC.Score>=70 AND SC.Sno=student.Sno;
   ```

1. 查询不及格的课程，并按课程号从大到小排列

   ```sql
   SELECT Cno FROM sc WHERE Score <60 ORDER BY Cno ;
   ```

1. 查询课程编号为 003 且课程成绩在 80 分以上的学生的学号和姓名;

   ```sql
   SELECT SC.Sno,Student.Sname FROM SC,Student WHERE SC.Sno=Student.Sno AND Score>80 AND Cno='003';
   ```

1. 求选了课程的学生人数

   ```sql
   SELECT COUNT(\*) FROM sc;
   ```

1. 查询选修“张老师”老师所授课程的学生中，成绩最高的学生姓名及其成绩

   ```sql
   SELECT Student.Sname,Score
   FROM Student,SC,Course C,Teacher
   WHERE Student.Sno=SC.Sno AND SC.Cno=C.Cno AND C.Tno=Teacher.Tno AND Teacher.Tname='张老师' AND SC.Score=(SELECT max(Score)FROM SC WHERE Cno=C.Cno );
   ```

1. 查询各个课程及相应的选修人数

   ```sql
   SELECT Cno,COUNT(*) FROM sc GROUP BY Cno;
   ```

1. 查询不同课程成绩相同的学生的学号、课程号、学生成绩

   ```sql
   SELECT DISTINCT A.Sno,B.Score FROM SC A ,SC B WHERE A.Score=B.Score AND A.Cno <>B.Cno ;
   ```

1. 查询每门功成绩最好的前两名

   ```sql

   SELECT t1.Sno AS 学生 ID,t1.Cno AS 课程 ID,Score AS 分数
   FROM SC t1
   WHERE Score IN (SELECT TOP 2 Score
   FROM SC
   WHERE t1.Cno= Cno
   ORDER BY Score DESC
   )
   ORDER BY t1.Cno;

   ```

1. 统计每门课程的学生选修人数（超过 10 人的课程才统计）。要求输出课程号和选修人数，查询结果按人数降序排列，查询结果按人数降序排列，若人数相同，按课程号升序排列

   ```sql
   SELECT Cno AS 课程号,COUNT(_) AS 人数
   FROM sc
   GROUP BY Cno
   ORDER BY COUNT(_) desc,Cno
   ```

1. 检索至少选修两门课程的学生学号

   ```sql
   SELECT Sno
   FROM sc
   GROUP BY Sno
   HAVING COUNT(\*) > = 2
   ```

1. 查询全部学生都选修的课程的课程号和课程名

   ```sql
   SELECT Cno,Cname
   FROM Course
   WHERE Cno in (SELECT Cno FROM sc GROUP BY Cno)
   ```

1. 查询没学过“张老师”老师讲授的任一门课程的学生姓名

   ```sql
   SELECT Sname FROM Student WHERE Sno not in (SELECT Sno FROM Course,Teacher,SC WHERE Course.Tno=Teacher.Tno AND SC.Cno=course.Cno AND Tname='张老师');
   ```

1. 查询两门以上不及格课程的同学的学号及其平均成绩

   ```sql
   SELECT Sno,avg(isnull(Score,0)) FROM SC WHERE Sno in (SELECT Sno FROM SC WHERE Score <60 GROUP BY Sno HAVING COUNT(*)>2)GROUP BY Sno;
   ```

1. 检索“004”课程分数小于 60，按分数降序排列的同学学号

   ```sql
   SELECT Sno FROM SC WHERE Cno='004'AND Score <60 ORDER BY Score desc;
   ```

## 数据更新

1. 把“SC”表中“张老师”老师教的课的成绩都更改为此课程的平均成绩;

   ```sql

   UPDATE SC
   SET Score = ( SELECT AVG(SC_2.Score)
   FROM SC SC_2
   WHERE SC_2.Cno = SC.Cno
   )
   FROM Course ,
   Teacher
   WHERE Course.Cno = SC.Cno
   AND Course.Tno = Teacher.Tno
   AND Teacher.Tname = '张老师'

   ```

1. 删除学习“张老师”老师课的 SC 表记录;

   ```sql
   DELETE SC
   FROM course ,
   Teacher
   WHERE Course.Cno = SC.Cno
   AND Course.Tno = Teacher.Tno
   AND Tname = '张老师'
   ```

1. 删除“002”同学的“001”课程的成绩

   ```sql
   DELETE FROM Sc WHERE Sno='001'AND Cno='001';
   ```

```sql
INSERT INTO "student" ("sno", "sname", "ssex", "sbirthday")
VALUES ('1', '小一', '男', '1995-1-1');
INSERT INTO "student" ("sno", "sname", "ssex", "sbirthday")
VALUES ('2', '小二', '男', '1995-2-1');
INSERT INTO "student" ("sno", "sname", "ssex", "sbirthday")
VALUES ('3', '小仨', '男', '1995-3-1');
INSERT INTO "student" ("sno", "sname", "ssex", "sbirthday")
VALUES ('4', '小四', '女', '1995-4-1');
INSERT INTO "student" ("sno", "sname", "ssex", "sbirthday")
VALUES ('5', '小五', '女', '1995-5-1');
INSERT INTO "student" ("sno", "sname", "ssex", "sbirthday")
VALUES ('6', '小六', '女', '1995-6-1');


INSERT INTO "teacher" ("tno", "tname")
VALUES ('t01', '张老师');
INSERT INTO "teacher" ("tno", "tname")
VALUES ('t02', '李老师');
INSERT INTO "teacher" ("tno", "tname")
VALUES ('t03', '王老师');
INSERT INTO "teacher" ("tno", "tname")
VALUES ('t04', '孙老师');
INSERT INTO "teacher" ("tno", "tname")
VALUES ('t05', '吴老师');

INSERT INTO "course" ("cno", "cname", "tno")
VALUES ('c01', '程序设计', 't01');
INSERT INTO "course" ("cno", "cname", "tno")
VALUES ('c02', '数据库', 't01');
INSERT INTO "course" ("cno", "cname", "tno")
VALUES ('c03', '计算机网路', 't02');
INSERT INTO "course" ("cno", "cname", "tno")
VALUES ('c04', '多媒体', 't03');

INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s01  ', 'c01', '61');
INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s01  ', 'c02', '62');
INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s01  ', 'c03', '63');
INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s01  ', 'c04', '64');

INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s02  ', 'c01', '71');
INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s02  ', 'c02', '72');
INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s02  ', 'c03', '73');
INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s02  ', 'c04', '74');


INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s03  ', 'c01', '81');
INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s03  ', 'c02', '82');
INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s03  ', 'c03', '83');
INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s03  ', 'c04', '84');


INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s04  ', 'c01', '91');
INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s04  ', 'c03', '93');
INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s04  ', 'c04', '94');


INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s05  ', 'c01', '91');
INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s05  ', 'c03', '93');


INSERT INTO "sc" ("sno", "cno", "score")
VALUES ('s06  ', 'c01', '100');
```

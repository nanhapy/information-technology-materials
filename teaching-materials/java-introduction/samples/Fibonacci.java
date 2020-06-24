public class Fibonacci {
  public static void main(String[] args) {
    int n = 12;
    int f1 = 0;
    int f2 = 1;// Fibonacci第一个和第二个数为1

    for (int i = 0; i <= n; i++) {// 输出多少个看自己需要
      int f = f2;
      f2 = f1 + f2;// 新的Fibonacci数
      f1 = f;

      System.out.println(f);
    }

  }
}
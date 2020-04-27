public class Fibonacci {
    public static void main(String[] args) {
        int n = 12;
        int f1 = 1;
        int f2 = 1;// Fibonacci第一个和第二个数为1
        int f3 = 0;// 接收新的Fibonacci数

        for (int i = 3; i <= n; i++) {// 输出多少个看自己需要
            f3 = f1 + f2;// 新的Fibonacci数
            f1 = f2;// 第i-1个数
            f2 = f3;// 第i个数
        }

        System.out.println(f3);
    }
}
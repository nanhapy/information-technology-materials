import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        float c = 0f;
        int sum = 0;
        while (true) {
            int a = input.nextInt();
            if (a == 0) {
                break;
            }
            sum += a;
            c++;
        }

        float v = 0f;
        if (c > 0) {
            v = sum / c;
        }
        System.out.println(v);
    }
}
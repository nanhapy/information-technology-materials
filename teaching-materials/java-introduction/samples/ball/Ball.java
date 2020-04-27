import java.util.Scanner;

public class Ball {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        // h记录球的初始高度

        double p = 3.14;

        System.out.println("圆柱的体积是:" + p);

        // printf("圆柱的体积是%d：",d);

        double h = input.nextDouble();

        // up记录小球反弹的距离

        double up = 0;

        // down记录小球下落的距离

        double down = 0;

        for (int i = 1; i < 10; i++) {

            down = down + h;

            up = up + h / 2;

            h = h / 2;

        }

        System.out.println("10次落地共经过多少米" + (down + up + h));

        System.out.println("第10次反弹高度" + h / 2);

        input.close();
    }
}
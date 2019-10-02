public class Volume2 {
    public static void main(String[] args) {
        Cylinder cylinder = new Cylinder();
        
        // Scanner input = new Scanner(System.in);

        Circle circle = new Circle();
        circle.setR(3);
        cylinder.setCircle(circle);
        cylinder.setHeight(5);

        System.out.println("底面半径为" + circle.getR() + "，高为" + cylinder.getHeight() + "的圆柱体的体积为：" + cylinder.getVolume());
    }
}

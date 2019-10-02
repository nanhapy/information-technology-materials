
public class Circle {

    final double PI = 3.14159265359;

    private double r;

    public double getR() {
        return r;
    }

    public void setR(double r) {
        this.r = r;   
    }

    public double getArea(){
        return this.r * this.r * PI;
    }
}

abstract class Shape{
             abstract void numberOfSides();
}
class Triangle extends Shape{
    void numberOfSides(){
        System.out.println("Triangle has 3 Sides");
    }
}
class Rectangle extends Shape{
    void numberOfSides(){
        System.out.println("Rectangle has 4 Sides");
    }
}
class Hexagon extends Shape{
    void numberOfSides(){
        System.out.println("Hexagon has 6 Sides");
    }
    public static void main(String[] args){
        Rectangle rect = new Rectangle();
        Triangle tri = new Triangle();
        Hexagon hex = new Hexagon();
        rect.numberOfSides();
        tri.numberOfSides();
        hex.numberOfSides();
    }
}
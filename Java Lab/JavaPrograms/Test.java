//Super Class
class Vehicle{
    int maxSpeed =120;
    void display(){
        System.out.println("Maximum Speed : "+maxSpeed);
    }
}
//Sub Class Car Extending Vehicle
class Car extends Vehicle{
    int maxSpeed =180;
    void display(){  // Method Overriding
        System.out.println("Maximum Speed : "+maxSpeed);
    }
}
//Driver Program to Test
class Test{
    public static void main(String args[]){
        Car small = new Car();
        small.display();
        System.out.println(small.maxSpeed);
    }
}
class Rectangle{
    int length;
    int breadth;

    Rectangle(){                // Default Constructor
        this(0);
        //length=0;
        //breadth=0;
    }

    Rectangle(int x){
        this(x,x);                // Constructor Chaining
       // length=x;
       // breadth=x;
    }
    Rectangle(int length,int breadth){     // Parameterized Constructor
        this.length=length;
        this.breadth=breadth;
    }

    void getData(int x,int y){
        length = x;
        breadth = y;
    }

    int rectArea(){
        int area = length*breadth;
        return area;
    }
    void display(){
        System.out.println("Area  = "+rectArea());  //Nesting of Methods 
    }

    public static void main(String args[]){
        Rectangle myrect1 = new  Rectangle(); // Creation
        Rectangle myrect2 = new  Rectangle();
        Rectangle myrect3 = new  Rectangle();
        Rectangle myrect4 = new  Rectangle(4,10);
        Rectangle myrect5 = new  Rectangle(5);
        myrect1.length=5;
        myrect1.breadth=10;
        int area1=myrect1.length*myrect1.breadth;
        myrect2.getData(15,10);
        int area2=myrect2.rectArea();
        int area3=myrect3.rectArea();
        int area4=myrect4.rectArea();
        int area5=myrect5.rectArea();
        System.out.println("Area 1 = "+area1);
        System.out.println("Area 2 = "+area2);
        System.out.println("Area 3 = "+area3);
        System.out.println("Area 4 = "+area4);
        System.out.println("Area 5 = "+area5);
    }
}
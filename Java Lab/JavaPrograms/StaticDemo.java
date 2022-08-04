class StaticDemo{
    public static void main(String args[]){
         // Test obj1=new Test();
        // obj1.show();
        Test.show();
        Test.a=5;
    }
}
class Test{
    int abc;
    static int a;              //Static Data Member
    static void show(){        //Static Method
        abc =0; //Error
       System.out.println("HELLO");
    }
}
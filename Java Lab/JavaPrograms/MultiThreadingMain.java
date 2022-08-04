import java.util.*;
class Thread1 extends Thread
{   int num;
    public void run(){
            Random obj = new Random();
            num=obj.nextInt(100);
            System.out.println("\n  NUMBER : "+num);
            Thread2 obj2 = new Thread2(num);
            Thread3 obj3 = new Thread3(num);
            if(num%2==0){
                obj2.start();
            }else {
                obj3.start();
            }
    }
}
class Thread2 extends Thread
{
    int num;
    public void run(){
        System.out.println("\n  SQUARE : "+num*num);
    }
    Thread2(int num) {
        this.num=num;
    }
}
class Thread3 extends Thread
{
    int num;
    public void run()
    {
        System.out.println("\n    CUBE : "+num*num*num);
    }
    Thread3(int num){
        this.num=num;
    }
}
public class MultiThreadingMain {
    public static void main(String[] args) throws InterruptedException{
        for(int i=0;i<5;i++){
            Thread1 obj1 = new Thread1();
            obj1.start();
            obj1.sleep(1000);
        }
    }
}
class Number{
    synchronized void print(int n){
        for(int i=1;i<=5;i++){
            System.out.println("Thread : "+n);
        }
    }
}
class Thread1 extends Thread{
    Number num;
    Thread1(Number num){
        this.num=num;
    }
    public void run(){
        num.print(1);
    }
}
class Thread2 extends Thread{
    Number num;
    Thread2(Number num){
        this.num=num;
    }
    public void run(){
        num.print(2);
    }
}

public class ThreadSynchronization{
    public static void main(String args[]){
        Number obj = new Number();
        Thread1 obj1 = new Thread1(obj);
        Thread2 obj2 = new Thread2(obj);
        obj1.start();
        obj2.start();
    }
}
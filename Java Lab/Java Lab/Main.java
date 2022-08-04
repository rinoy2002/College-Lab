import factorial.FactorialNum;
import reversenum.ReverseNum;
import java.util.*;
public class Main{
    public static void main(String args[]){
        int num1,num2;
        Scanner sc = new Scanner(System.in);
        FactorialNum obj = new FactorialNum();
        System.out.println(" --- REVERSE --- ");
        System.out.print(" Enter Number : ");
        num1=sc.nextInt();
        System.out.print(" Reverse : ");
        System.out.print(ReverseNum.calcReverse(num1));
        System.out.println("\n --- FACTORIAL --- ");
        System.out.print(" Enter Number : ");
        num2=sc.nextInt();
        if(num2<0){
            System.out.println("Factorial doesn't Exists");
        }else{
            System.out.print(" Factorial : ");
            System.out.print(obj.calcFactorial(num2));
        }
    }
}
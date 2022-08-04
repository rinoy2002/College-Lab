import studpack.*;

public class Hybrid{
    public static void main(String[] args){
         Result S1 =new Result(" Rinoy ",56,97,96,98);
         Result S2 =new Result(" Royal ",58,78,60,50);
         Result S3 =new Result(" Tejas ",60,90,89,91);
         Result S4 =new Result("  Alex  ",05,83,89,85);
         Result S5 =new Result(" Joseph",45,90,81,89);
         System.out.println("Roll No.   Name        Total    Grade");
         S1.displayTotal();
         S2.displayTotal();
         S3.displayTotal();
         S4.displayTotal();
         S5.displayTotal();
    }
}
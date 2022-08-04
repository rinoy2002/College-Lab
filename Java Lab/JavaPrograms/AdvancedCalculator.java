class Calculator{
    int add( int a,int b){
        return a+b;
    }
    int subtract( int a,int b){
        return a-b;
    }
}
public class AdvancedCalculator extends Calculator{
    int multiply( int a,int b){
        return a*b;
    }
    int divide( int a,int b){
        return a/b;
    }
    public static void main (String args[]){
        AdvancedCalculator A = new AdvancedCalculator();
        System.out.println("Result ="+A.add(5,5));
        System.out.println("Result ="+A.subtract(5,5));
        System.out.println("Result ="+A.multiply(5,5));
        System.out.println("Result ="+A.divide(5,5));

    }
}
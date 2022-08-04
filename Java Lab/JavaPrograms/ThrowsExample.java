public class ThrowsExample {
   static void number(int x) throws ArithmeticException {
        if (x < 10) {
            throw new ArithmeticException("Error! : Number should be Greater than 10");
        }
        else {
            System.out.println("Number is be Greater than 10");
        }
    }

    public static void main(String[] args) {
       int y=Integer.parseInt(args[0]);
       number(y);
    }
}

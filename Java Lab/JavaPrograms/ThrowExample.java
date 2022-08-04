public class ThrowExample {

    public static void main(String[] args) {
       int x=0 ;
        for (String arg:args) {
            x++;
        }

        if (x!=2) {
            throw new ArithmeticException("Insufficient Arguments passed");
        }
        else {
            int sum = Integer.parseInt(args[0])+Integer.parseInt(args[1]);
            System.out.println("Sum : "+ sum);
        }
    }
}

public class MultipleCatch {
    public static void main(String args[]) {
        int[] arr = {67, 20, 39, 2, 10, 18};
        try {
            int res = arr[6];
            int div = arr[2]/0;
            System.out.println(res);
        }
        catch(ArrayIndexOutOfBoundsException exp1){
            System.out.println(exp1);

        }
        catch(ArithmeticException exp2) {
            System.out.println(exp2);
        }
    }
}
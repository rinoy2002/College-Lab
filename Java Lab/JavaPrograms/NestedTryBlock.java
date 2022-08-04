class NestedTryBlock{

    public static void main(String args[]){

        try {

            int[] arr = {67, 20, 39, 2, 10, 18};
            System.out.println("Element at Index 4 : " +arr[4]);
            try {

                int x = arr[2]/ 10;
                System.out.println("X : " +x);
                try {

                    int y = arr[9]/ 0;
                    System.out.println("Y : " +y);
                }
                catch (ArrayIndexOutOfBoundsException e3) {
                    System.out.println(e3);
                    System.out.println("Element at such Index doesn't Exists");
                }
                catch (Exception e4) {
                    System.out.println(e4);
                }
            }
            catch (ArithmeticException e2) {
                System.out.println(e2);
            }
        }
        catch (ArrayIndexOutOfBoundsException e1) {
            System.out.println(e1);
            System.out.println("Element at such Index doesn't Exists");
        }
    }
}

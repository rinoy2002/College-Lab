public class SecondSmallest {
    public static void main(String[] args) {
        int i, min,temp=0;
        int[] arr = new int[]{998, 221, 233, 412, 425, 696, 567, 548, 99, 1000};
        min = arr[0];
        for (i = 1; i < 10; i++) {
            if (min>arr[i]) {
                temp = min;
                min = arr[i];
            }
        }
        System.out.println(temp);
    }
}
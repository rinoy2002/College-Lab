import java.util.*;
public class QuickSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of N: ");
        int n = sc.nextInt();
        String arr[] = new String[n];
        sc.nextLine();
        for(int i=0; i<n; i++)
        {
            System.out.print("Enter name [" + (i+1) +"]: ");
            arr[i] = sc.nextLine();
        }
        QuickSort obj = new QuickSort();
        obj.sort(arr, 0, arr.length - 1);
        for (String i : arr) {
            System.out.print(" "+ i + " ");
        }
    }
    int partition(String [] arr, int p, int r) {
        String pivot = arr[r];
        int i = (p - 1);
        String tmp;
        for (int j = p ; j < r ; j++) {
            if (arr[j].compareTo(pivot) < 0) {
                i = i + 1;
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        tmp = arr[i+1];
        arr[i+1] = arr[r];
        arr[r] = tmp;
        return i + 1;
    }
    void sort(String[] arr, int p, int r) {
        if (p < r) {
            int q = partition(arr, p, r);
            sort(arr, p, q - 1);
            sort(arr, q + 1, r);
        }
    }
}
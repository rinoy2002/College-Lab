import java.io.*;
class BinarySearch{
    public static void main(String args[]) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[50];
        int size,search;
        System.out.print("Enter the size of array : ");
        size=Integer.parseInt(br.readLine());
        System.out.println("Enter the Numbers : ");
        for(int i=0;i<size;i++){
            arr[i]=Integer.parseInt(br.readLine());
        }
        System.out.print("Enter the element to be searched : ");
        search = Integer.parseInt(br.readLine());
        int first=0;
        int last=size-1;
        int mid = (first + last)/2;
        while( first <= last ){
            if ( arr[mid] < search){
                first = mid + 1;
            }else if ( arr[mid] == search){
                System.out.println("Element found at index : " + mid);
                break;
            }else{
                last = mid-1;
            }
            mid =(first + last)/2;
        }
        if ( first > last ){
            System.out.println("Element is not found!");
        }
    }
}
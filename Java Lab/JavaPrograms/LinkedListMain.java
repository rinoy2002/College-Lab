import java.util.*;
import java.io.*;

class LinkedListMain {
    public static void main(String[] args) throws IOException{
        LinkedList<String> data = new LinkedList<>();
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int ans=1;
        System.out.println(" \n----  LINKED LIST ---- \n");
        System.out.println("  1. Insert Operation ");
        System.out.println("  2. Delete Operation ");
        System.out.println("  3. Display List ");
        System.out.println("  4. Exit \n");
        while(ans!=4) {
            System.out.print("\n Enter choice (1/2/3/4) :");
            ans=Integer.parseInt(br.readLine());
            switch(ans){
                case 1 : System.out.println("\n ----  INSERT ---- ");
                         System.out.print("Enter the Data : ");
                         data.add(br.readLine());
                         break;
                case 2 : System.out.println("\n ----  DELETE ----");
                         System.out.print("Enter the Data to delete : ");
                         data.remove(br.readLine());
                         System.out.println(data);
                         break;
                case 3 : System.out.println("\n ----  DISPLAY ----");
                         System.out.println(data);
                         break;
                case 4 : break;
                default: System.out.println("Invalid Choice");
            }

        }
    }
}
import java.util.StringTokenizer;
import java.io.*;
public class SumOfNumbers{
    public static void main(String args[]) throws IOException{
        String num;
        int sum =0;
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter Numbers (seperated with commas) : ");
        num=br.readLine();
        StringTokenizer st = new StringTokenizer(num,",");
        while (st.hasMoreTokens()) {
            sum=sum+Integer.parseInt(st.nextToken());
        }
        System.out.print("Sum is : "+sum);
    }
}
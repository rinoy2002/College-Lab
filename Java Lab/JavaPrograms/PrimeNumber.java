public class PrimeNumber {
    public static void main(String[] args) {
        int x=23,i,n=0;
        for (i=2;i<=x/2;i++)
        {
            if(x==0||x==1){
            n=1;
            }
            else if(x%i==0){
                n=1;
                break;
            }
        }

            if(n==0){
                System.out.println("PRIME NUMBER");
            }else{
                System.out.println("NOT PRIME NUMBER");
            }
    }
}

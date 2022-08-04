public class TryFinally{
    public static void main(String args[]){
        try{
            int a=5/0;
            System.out.println(a);
        }
        finally{
            System.out.println("Finally Block is Always Executed");
        }
    }
}
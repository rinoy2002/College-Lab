package reversenum;
public class ReverseNum{
    public static int calcReverse(int num){
        int rev = 0,x;
        while(num!= 0) {
            x = num % 10;
            rev = rev * 10 + x;
            num = num/10;
        }
        return rev;
    }
}
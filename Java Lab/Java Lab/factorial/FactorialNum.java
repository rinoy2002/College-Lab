package factorial;
public class FactorialNum{
    public double calcFactorial(int num){
        double fact = 1;
        int x;
        while(num > 0) {
            fact = fact * num;
            num = num -1;
        }
        return fact;
    }
}
public class BankAccount {
    String Name;
    int AccNumber;
    String AccType;
    float Amt;

    BankAccount() {
        Amt = 0;
    }

    BankAccount(String n,int ac,String t){
        Name=n;
        AccNumber=ac;
        AccType=t;
    }
    void deposit (float a){
        Amt=a;
        System.out.println("------DEPOSIT------");
        System.out.println("Rs"+Amt+" Deposited Sucessfully");
    }
    void withdraw(float w){
        System.out.println("\n\n------WITHDRAWAL------");
        System.out.println("Your Balance : "+ Amt);
        Amt=Amt-w;
        System.out.println("Transaction of Rs"+w+" is Sucessful");
        System.out.println("Your Remaining Balance : "+ Amt);
    }
    void info(){
        System.out.println("\n\n------INFO------");
        System.out.println("Your Name : "+ Amt);
        System.out.println("Your Account Number : "+AccNumber);
        System.out.println("Your Account Type : "+ AccType);
        System.out.println("Your Balance : "+ Amt);
    }
    public static void main (String args[]){
        BankAccount Acc1=new BankAccount("Rinoy",123456,"Savings");
        Acc1.deposit(10000);
        Acc1.withdraw(1000);
        Acc1.info();
    }
}
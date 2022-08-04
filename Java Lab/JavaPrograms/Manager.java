class Employee{
    String name;
    int age;
    String phoneNumber;
    String address;
    double salary;
    public void printSalary(){
       System.out.println("Salary = $"+salary);
       System.out.println();
    }
    Employee(String a, int b, String c, String d, double e){
        name=a;
        age=b;
        phoneNumber=c;
        address=d;
        salary=e;
    }
}
public class Manager extends Employee{
    String department;
    Manager(String a, int b, String c, String d, double e,String f){
        super(a,b,c,d,e);
        department=f;
    }
    public void printInfo(){
        System.out.println("--- Manager Information ---");
        System.out.println();
        System.out.println("Name = "+name);
        System.out.println("Age = "+age);
        System.out.println("Phone Number = "+phoneNumber);
        System.out.println("Address = "+address);
        System.out.println("Department = "+department);
        System.out.println();
    }
    public static void main(String args[]){
        Manager m1 =new Manager("Alexis",26,"9913891231","East City London UK",9000,"Sales");
        Officer o1 =new Officer("John"  ,28,"9671290231","Los Angeles New York US",5000,"Cyber Security");
        m1.printInfo();
        m1.printSalary();
        o1.printInfo();
        o1.printSalary();
    }

}
class Officer extends Employee{
    String specialization;
    Officer(String a, int b, String c, String d, double e,String f ){
        super(a,b,c,d,e);
        specialization=f;
    }
    public void printInfo(){
        System.out.println("--- Officer Information ---");
        System.out.println();
        System.out.println("Name = "+name);
        System.out.println("Age = "+age);
        System.out.println("Phone Number = "+phoneNumber);
        System.out.println("Address = "+address);
        System.out.println("Specialization = "+specialization);
        System.out.println();
    }
}
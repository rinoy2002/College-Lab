class Employee {
    static double salary;
    static String classname;
    static void display(String clsname) {
        classname = clsname;
        System.out.println("Name of class is " + classname);
    }
    static void calcSalary(double sal) {
        salary = sal;
        System.out.println("Salary of Employee is " + sal);
    }
}
class Engineer extends Employee {
    public static void main(String args[]){
        Employee.display("Employee");
        Employee.calcSalary(10000);
        Engineer obj = new Engineer();
        obj.display("Engineer");
        obj.calcSalary(20000);
    }
}
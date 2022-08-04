package studpack;

class Student {
    String name;
    int rollno;
    float mark1,mark2,mark3;
    Student(){
        mark1 = 0;
        mark2 = 0;
        mark3 = 0;
        rollno = 0;
    }
    Student(String name,int rollno,float mark1,float mark2,float mark3){
        this.name = name;
        this.mark1 = mark1;
        this.mark2 = mark2;
        this.mark3 = mark3;
        this.rollno = rollno;
    }
}

interface Sports{
    char grade='A';
    char displayGrade();
}

public class Result extends Student implements Sports{

    float total;
    public char displayGrade(){
        return grade;
    }
    public void displayTotal(){
        total=mark1+mark2+mark3;
        System.out.println("  "+rollno+"      "+name+"      "+total+"      "+displayGrade());
    }
    public Result(String name,int rollno,float mark1,float mark2,float mark3){
        super(name,rollno,mark1,mark2,mark3);
    }
}
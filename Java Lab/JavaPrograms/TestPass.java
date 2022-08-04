class ObjectPassDemo{
    int a;
    int b;
    ObjectPassDemo(int i,int j){
        a=i;
        b=j;
    }
    boolean equalTo(ObjectPassDemo o){
        return (o.a==a&&o.b==b);
    }
}
class TestPass{
    public static void main(String args[]){
        ObjectPassDemo ob1 = new ObjectPassDemo(100,22);
        ObjectPassDemo ob2 = new ObjectPassDemo(100,22);
        ObjectPassDemo ob3 = new ObjectPassDemo(-1,-1);
        System.out.println("ob1 == ob1 :"+ob1.equalTo(ob1));
        System.out.println("ob1 == ob2 :"+ob1.equalTo(ob2));
        System.out.println("ob1 == ob3 :"+ob1.equalTo(ob3));
    }
}
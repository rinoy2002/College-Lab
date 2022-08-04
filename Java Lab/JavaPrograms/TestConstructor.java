class Box{
    double height,width,depth;
    Box( double w, double h, double d){
        height=h;
        width=w;
        depth=d;
    }
    Box(Box ob){
        height=ob.height;
        width=ob.width;
        depth=ob.depth;
    }
    double volume(){
        return height*width*depth;
    }
}
class TestConstructor{
    public static void main(String args[]){
        Box mybox = new Box(10,20,15);
        Box myclone = new Box(mybox);
        System.out.println("Volume mybox   :"+mybox.volume());
        System.out.println("Volume myclone :"+myclone.volume());

 }
}
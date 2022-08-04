import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class SampleEvent
{
    JLabel jlab1,jlab2;
    JTextField inchfield,feetfield;

    SampleEvent(){

        JFrame jfrm=new JFrame("Convertor");
        JPanel panel1 = new JPanel();
        JPanel panel2 = new JPanel();
        jfrm.setLayout(new FlowLayout());
        panel1.setLayout(new GridLayout(1,4));
        panel1.setLayout(new GridLayout(1,2));
        jfrm.setSize(500,500);
        jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        jlab1=new JLabel("Inches");
        inchfield=new JTextField("0");
        jlab2=new JLabel("Feet");
        feetfield=new JTextField("0");

        JButton inchbtn=new JButton("Convert to inches");
        JButton feetbtn=new JButton("Convert to Feet");
        JButton closebtn=new JButton("Close");
        JButton resetbtn=new JButton("Reset");


        inchbtn.addActionListener(
                new ActionListener(){
                    public void actionPerformed(ActionEvent ae) {
                        float num = Float.parseFloat(feetfield.getText());
                        inchfield.setText(num*12 + "");
                        feetfield.setText(num+"");
                    }
                });

        feetbtn.addActionListener(
                new ActionListener() {
                    public void actionPerformed(ActionEvent ae) {
                        float num = Float.parseFloat(inchfield.getText());
                        feetfield.setText(num/12 + "");
                        inchfield.setText(num+"");
                    }
                });

        resetbtn.addActionListener(
                new ActionListener() {
                    public void actionPerformed(ActionEvent ae) {
                        feetfield.setText("0");
                        inchfield.setText("0");
                    }
                });

        closebtn.addActionListener(
                new ActionListener(){
                    public void actionPerformed(ActionEvent ae) {
                        System.exit(0);
                    }
                });

        panel1.add(jlab1);
        panel1.add(inchfield);
        panel1.add(jlab2);
        panel1.add(feetfield);

        panel2.add(inchbtn);
        panel2.add(feetbtn);

        jfrm.add(closebtn);
        jfrm.add(resetbtn);
        jfrm.add(panel1);
        jfrm.add(panel2);


        jfrm.setVisible(true);
        panel1.setVisible(true);
        panel2.setVisible(true);

    }

    public static void main(String args[]){
        SampleEvent s =new SampleEvent();
    }
}
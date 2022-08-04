import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class TrafficLight
{
    TrafficLight() {
        JFrame frame = new JFrame("Traffic Light");
        JRadioButton red = new JRadioButton();
        JRadioButton yellow = new JRadioButton();
        JRadioButton green = new JRadioButton();
        ButtonGroup traffic = new ButtonGroup();
        traffic.add(red);
        traffic.add(yellow);
        traffic.add(green);
        red.setBackground(Color.WHITE);
        yellow.setBackground(Color.WHITE);
        green.setBackground(Color.WHITE);
        frame.add(red);
        frame.add(yellow);
        frame.add(green);
        frame.setSize(300,100);
        frame.setLayout(new GridLayout(1,3));
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        red.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                red.setBackground(Color.RED);
                yellow.setBackground(Color.WHITE);
                green.setBackground(Color.WHITE);
                red.setText("STOP");
                yellow.setText("");
                green.setText("");
            }
        });
        yellow.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae){
                red.setBackground(Color.WHITE);
                yellow.setBackground(Color.YELLOW);
                green.setBackground(Color.WHITE);
                red.setText("");
                yellow.setText("WAIT");
                green.setText("");
            }
        });
        green.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae){
                red.setBackground(Color.WHITE);
                yellow.setBackground(Color.WHITE);
                green.setBackground(Color.GREEN);
                red.setText("");
                yellow.setText("");
                green.setText("GO");
            }
        });
    }
    public static void main(String[] args)
    {
        new TrafficLight();
    }
}
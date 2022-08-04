import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class CalculatorSwing {
    CalculatorSwing(){
        JFrame frame=new JFrame("Calculator");
        JPanel panel1=new JPanel();
        JPanel panel2=new JPanel();

        frame.setLayout(new BorderLayout());
        panel2.setLayout(new GridLayout(4,5));
        frame.setSize(350,350);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JButton b0=new JButton("0");
        JButton b1=new JButton("1");
        JButton b2=new JButton("2");
        JButton b3=new JButton("3");
        JButton b4=new JButton("4");
        JButton b5=new JButton("5");
        JButton b6=new JButton("6");
        JButton b7=new JButton("7");
        JButton b8=new JButton("8");
        JButton b9=new JButton("9");
        JButton b10=new JButton("+");
        JButton b11=new JButton("-");
        JButton b12=new JButton("/");
        JButton b13=new JButton("*");
        JButton b14=new JButton("%");
        JButton b15=new JButton("^");
        JButton b16=new JButton("=");
        JButton b17=new JButton("AC");
        JButton b18=new JButton("DEL");
        JButton b19=new JButton(".");

        JTextField input = new JTextField(30);

        input.setHorizontalAlignment(JTextField.CENTER);
        panel1.add(input);
        panel2.add(b1);
        panel2.add(b2);
        panel2.add(b3);
        panel2.add(b10);
        panel2.add(b17);

        panel2.add(b4);
        panel2.add(b5);
        panel2.add(b6);
        panel2.add(b11);
        panel2.add(b18);

        panel2.add(b7);
        panel2.add(b8);
        panel2.add(b9);
        panel2.add(b12);
        panel2.add(b16);

        panel2.add(b0);
        panel2.add(b19);
        panel2.add(b13);
        panel2.add(b14);
        panel2.add(b15);

        frame.add(panel1,BorderLayout.NORTH);
        frame.add(panel2,BorderLayout.CENTER);

        frame.setVisible(true);
        b0.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }
                input.setText(input.getText()+"0");
            }});
        b1.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }
                input.setText(input.getText()+"1");
            }});
        b2.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }
                input.setText(input.getText()+"2");
            }});
        b3.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }
                input.setText(input.getText()+"3");
            }});
        b4.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }
                input.setText(input.getText()+"4");
            }});
        b5.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }
                input.setText(input.getText()+"5");
            }});
        b6.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }
                input.setText(input.getText()+"6");
            }});
        b7.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }
                input.setText(input.getText()+"7");
            }});
        b8.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }
                input.setText(input.getText()+"8");
            }});
        b9.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }
                input.setText(input.getText()+"9");
            }});
        b10.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }
                input.setText(input.getText()+"+");
            }});
        b11.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }
                input.setText(input.getText()+"-");
            }});
        b12.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }
                input.setText(input.getText()+"/");
            }});
        b13.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }
                input.setText(input.getText()+"*");
            }});
        b14.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }
                input.setText(input.getText()+"%");
            }});
        b15.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }
                input.setText(input.getText()+"^");
            }});
        b16.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                String inp = input.getText();
                int i = 0;
                float a, b, result = 0;
                char op = inp.charAt(0);
                try
                {
                    while(op != '+' && op != '-' && op!= '*' && op != '/' && op != '%' && op != '^')
                    {
                        op = inp.charAt(i);
                        i++;
                    }
                    a = Float.parseFloat(inp.substring(0,i-1));
                    b = Float.parseFloat(inp.substring(i,inp.length()));
                    switch(op)
                    {
                        case '+': result = a+b;
                                  break;
                        case '-': result = a-b;
                                  break;
                        case '/': try{
                                      result = a/b;
                                  }catch(Exception e1){}
                                  break;
                        case '*': result = a*b;
                                  break;

                        case '%': result = a%b;
                                  break;
                        case '^': result = (float) Math.pow(a,b);
                                  break;
                    }
                    if(b!=0){
                        input.setText(result+"");
                    }else{
                        input.setText("Not Defined");
                    }
                }catch(Exception e2){
                    input.setText("Invalid Input");
                }
            }});
        b17.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                input.setText("");
            }});
        b18.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }else {
                    try {
                        input.setText(input.getText().substring(0, input.getText().length() - 1));
                    } catch (Exception e3) {
                    }
                }
            }});
        b19.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                if(input.getText().equals("Invalid Input")||input.getText().equals("Not Defined")){
                    input.setText("");
                }
                input.setText(input.getText()+".");
            }});
    }

    public static void main(String[] args) {
        new CalculatorSwing();
    }
}
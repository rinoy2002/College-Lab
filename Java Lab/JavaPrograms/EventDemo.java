import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
class EventDemo {
    JLabel jlab;
    EventDemo() {
        // Create a new JFrame container.
        JFrame jfrm = new JFrame("An Event Example");
        // Specify FlowLayout for the layout manager.
        jfrm.setLayout(new FlowLayout());
        // Give the frame an initial size.
        jfrm.setSize(500, 250);
        // Terminate the program when the user closes the application.
        jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Create a text-based label.
        jlab = new JLabel("Press a button.");
        // Add the label to the content pane.
        jfrm.add(jlab);
        // Make two buttons.
        JButton jbtnAlpha = new JButton("Alpha");
        JButton jbtnBeta = new JButton("Beta");
        // Add action listener for Alpha.
        jbtnAlpha.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                jlab.setText("Alpha was pressed.");
            } });
        jbtnBeta.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                jlab.setText("Beta was pressed.");
            } });
        // Add the buttons to the content pane.
        jfrm.add(jbtnAlpha);
        jfrm.add(jbtnBeta);

        // Display the frame.
        jfrm.setVisible(true);
    }
    public static void main(String args[]) {
        new EventDemo();
    }
}
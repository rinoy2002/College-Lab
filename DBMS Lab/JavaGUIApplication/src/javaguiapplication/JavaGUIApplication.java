
package javaguiapplication;

import java.sql.*;
import javax.swing.JOptionPane;

public class JavaGUIApplication {
    public static Connection con;
 
    public static void main(String[] args) {
       try{
           Class.forName("com.mysql.jdbc.Driver");
           con=DriverManager.getConnection("jdbc:mysql://localhost:3306/lab","root","");
           RegistrationForm obj =new RegistrationForm();
           obj.setVisible(true);
       }catch(Exception e){
           JOptionPane.showMessageDialog(null, e);
       }
    }
    
}
 
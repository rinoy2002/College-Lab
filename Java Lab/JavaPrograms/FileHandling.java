import java.io.*;

public class FileHandling {
    public static void main(String[] args) throws IOException {
        String content;
        int i;
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("\n   Creating File \n");
        try {
            File myObj = new File("myDocument.txt");
            if (myObj.createNewFile()) {
                System.out.println("File created : " + myObj.getName());
            } else {
                System.out.println("File already exists.");
            }
        } catch (IOException e1) {
            System.out.println("An error has occurred during File Creation.");
        }
        System.out.println("\n   Writing to File \n");
        try {
            FileWriter myWriter = new FileWriter("myDocument.txt");
            System.out.print("Enter the Content : ");
            content=br.readLine();
            myWriter.write(content);
            myWriter.close();
            System.out.println("Successfully wrote to the file.");
        } catch (IOException e2) {
            System.out.println("An error occurred during writing to File.");
        }
        System.out.println("\n   Reading from File : myDocument\n");
        File newObj = new File("myNewDocument.txt");
        newObj.createNewFile();
        FileWriter newWriter = new FileWriter("myNewDocument.txt");
        FileReader fr=null;
        try
        {
            fr = new FileReader("myDocument.txt");
            while ((i=fr.read())!=-1){
                newWriter.write((char)i);
            }
        }
        catch (FileNotFoundException e3)
        {
            System.out.println("File not found");
        }
        System.out.println("Successfully wrote to the file : myNewDocument.txt");
        newWriter.close();
        fr.close();
    }
}

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.FileReader;
public class fileClass {
    public static void main(String[] args) {
        // file = An abstract representation of file and directory pathnames

        File file = new File("C:\\Users\\Pedro\\OneDrive\\Área de Trabalho\\study\\Readme.md");
        
        try{
            FileWriter writer =  new FileWriter("text.txt");
            writer.write("Test line writer");
            writer.close();
        } 
        catch (IOException e) {
            e.printStackTrace();
        }
        try{
            FileReader reader =  new FileReader("text.txt");
            int data;
            while ((data = reader.read()) != -1){
                System.out.print((char)data);
            }
            reader.close();
        } 
        catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println();
        if (file.exists()){
            System.out.println("This file exists");
            
        }
    }
}

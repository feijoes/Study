import javax.sound.sampled.*;
import java.io.File;
import java.util.Scanner;
public class audioplayer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        File file = new File("music.wav");
        AudioInputStream audioStream =  AudioSystem.getAudioInputStream(file);
        Clip clip =  AudioSystem.getClip();

        clip.open(audioStream);

        clip.start();
        String response = scanner.next();

        while (!response.toUpperCase().equals("Q")){
            System.out.println("P (play)");
            System.out.println("S (stop)");
            System.out.println("R (reset)");
            System.out.print("Q (quit)");
            System.out.print("Enter your choise");
            response = scanner.next();

            switch(response.toUpperCase()){
                case ("P"): clip.start();
                break;
                case ("S"): clip.stop();
                break;
                case ("R"): clip.setMicrosecondPosition(0);
                break;
                case ("Q"): clip.close();
                break;
                default: System.out.println("Invalid choice");
            }
        }
    }  


}

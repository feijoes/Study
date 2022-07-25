import javax.swing.JFrame;
import javax.swing.JLabel;
public class Jframe {
    public static void main(String[] args)  {
        // Jframe = a GUI window to add componets to

        JLabel label =  new JLabel("This is a label");
        label.setHorizontalTextPosition(JLabel.CENTER);
        JFrame frame = new JFrame();

        frame.setTitle("Title");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(420,420);
        frame.setResizable(false);
        frame.setVisible(true);
        frame.add(label);
       
    }
}

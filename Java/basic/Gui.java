import javax.swing.JOptionPane;

public class Gui {
    public static void main(String[] args){
        String name = JOptionPane.showInputDialog( "Your name");
        JOptionPane.showMessageDialog(null, "hello "+name);

        int age = Integer.parseInt(JOptionPane.showInputDialog("Your age "));
        JOptionPane.showMessageDialog(null, "You are "+age+" Years old");

        double height = Double.parseDouble(JOptionPane.showInputDialog("Your height "));
        JOptionPane.showMessageDialog(null, "You are "+height+" Years old");

    }
    
}

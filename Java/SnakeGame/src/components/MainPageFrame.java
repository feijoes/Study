package components;

import pages.Mainpage;

import javax.swing.*;
import java.awt.*;


public class MainPageFrame extends JFrame {
    JButton button;
    JLabel label;
    JPanel panel2;
    JPanel panel1 ;
    public MainPageFrame(){
        this.setTitle("Snake Game");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setSize(500,500);
        this.getContentPane().setLayout(new GridLayout(2,2));
        this.setIconImage( new ImageIcon("logo.png").getImage());
        this.getContentPane().setBackground(Color.lightGray);

        panel2 = new JPanel();
        panel1 = new JPanel();

        button = new JButton();
        button.setFocusPainted(false);
        button.setFocusable(false);

        button.setText("Start Game");
        button.setIcon(new ImageIcon(new ImageIcon("start.png").getImage().getScaledInstance(30, 30, Image.SCALE_DEFAULT)));
        panel2.add(button);

        label = new JLabel("Snake Game",  SwingConstants.CENTER);
        label.setFont(new Font(label.getFont().getName(), label.getFont().getStyle(), 40));
        label.setPreferredSize(new Dimension(400, 200));
        label.setLocation(300,700);
        panel1.add(label);


        panel1.setVisible(true);
        panel2.setVisible(true);
        this.add(panel1);
        this.add(panel2);
        this.setVisible(true);
    }

    public JButton getButton(){
        return button;
    }
    public void setButtonListenert(Mainpage e){
        button.addActionListener(e);
    }

}

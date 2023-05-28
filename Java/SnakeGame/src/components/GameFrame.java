package components;

import pages.Mainpage;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class GameFrame extends JFrame {
    Timer timer;
    public static boolean end = false;
    public GameFrame(){
        Timer timer =new Timer(500,e ->{
            if (end){
                this.dispose();
                new Mainpage();
            }


        });
        timer.setInitialDelay(2600);
        timer.start();


        this.setTitle("Snake Game");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setSize(500,500);
        this.getContentPane().setLayout(new BorderLayout());
        this.setIconImage( new ImageIcon("logo.png").getImage());
        this.getContentPane().setBackground(Color.lightGray);
        this.setMinimumSize(new Dimension(400, 400));

        KeyListener listener = new KeyListener() {
            @Override
            public void keyPressed(KeyEvent event) {
                if ((Snake.direction == "Right"  || Snake.direction == "Left" )&& (KeyEvent.getKeyText(event.getKeyCode()) == "Up" || KeyEvent.getKeyText(event.getKeyCode()) == "Down")){
                    Snake.direction = KeyEvent.getKeyText(event.getKeyCode());
                } else if ((Snake.direction == "Up"  || Snake.direction == "Down" )&& (KeyEvent.getKeyText(event.getKeyCode()) == "Left" || KeyEvent.getKeyText(event.getKeyCode()) == "Right")) {
                    Snake.direction = KeyEvent.getKeyText(event.getKeyCode());
                }
            }
            @Override
            public void keyReleased(KeyEvent e) {}
            @Override
            public void keyTyped(KeyEvent event) {}
        };
        addKeyListener(listener);


        class a extends JPanel{
            a(Color a,int w, int h){
                this.setBackground(a);
                this.setPreferredSize(new Dimension(w,h));
            }
        }

        this.add(new Squares(),BorderLayout.CENTER);
        this.add(new a(Color.gray,70,70),BorderLayout.EAST);
        this.add(new a(Color.gray,70,70),BorderLayout.WEST);
        this.add(new a(Color.gray,70,70),BorderLayout.NORTH);
        this.add(new a(Color.gray,70,70),BorderLayout.SOUTH);
        this.setVisible(true);
    }
}

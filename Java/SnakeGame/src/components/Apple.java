package components;

import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class Apple {

    Random r = new Random();
    public int y = r.nextInt(21);
    public int x = r.nextInt(20);
    Apple(){

        while (true) {
            if (Squares.squares[y][x] == null) {
             break;
            } else if (Squares.squares[y][x].getBackground() == Color.GREEN) {
             break;
            }
            y = r.nextInt(21);
            x = r.nextInt(20);
        }

        JLabel apple = new JLabel();
        apple.setBorder(BorderFactory.createLineBorder(Color.BLACK, 1));
        apple.setBackground(Color.red);
        apple.setOpaque(true);
        apple.setVisible(true);
        Squares.squares[y][x] = apple;
    }

    public JLabel actualize(){
        JLabel apple = new JLabel();
        apple.setBorder(BorderFactory.createLineBorder(Color.BLACK, 1));
        apple.setBackground(Color.red);
        apple.setOpaque(true);
        apple.setVisible(true);
        Squares.squares[y][x] = apple;
        return apple;

    }
}

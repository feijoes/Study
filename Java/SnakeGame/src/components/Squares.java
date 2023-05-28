package components;

import javax.swing.*;
import java.awt.*;

public class Squares extends JPanel {

    static public JLabel[][]squares = new JLabel[21][20];
    static public int[][] squarestime = new int[21][20];

    private boolean start = true;
    Timer timer;

    Apple apple = new Apple();
    public JLabel addSquare(int i, int j) {
        JLabel square = new JLabel();
        square.setBorder(BorderFactory.createLineBorder(Color.BLACK, 1));
        square.setOpaque(true);
        square.setVisible(true);
        if ((i == Snake.y && (j >= Snake.x -2 && j <= Snake.x)) && start) {
            square.setBackground(Color.GREEN);

            squarestime[i][j] = j - 6;
        }
        squares[i][j] = square ;
        return square;

    }
    public Squares(){


        new Snake();

        this.setBackground(Color.gray);
        this.setLayout(new GridLayout(22,22,0,0));
        for (int i=0; i<=20;i++){
            for (int j=0;j<=19;j++){
                this.add(addSquare(i,j));
            }
        }
        start = false;

        this.setVisible(true);
        timer = new Timer(500, e -> actualize());
        timer.setInitialDelay(2600);
        timer.start();
    }

    public void actualize(){
        this.removeAll();

        for (int i=0; i<=20;i++){
            for (int j=0;j<=19;j++){
                if (squarestime[i][j] > 0){
                    squarestime[i][j]-=1;
                    this.add(squares[i][j]);
                } else if (apple.x == j && apple.y == i){
                    this.add(apple.actualize());
                }else {
                    this.add(addSquare(i,j));
                }
            }
        }


        this.revalidate();
        this.repaint();
    }

}

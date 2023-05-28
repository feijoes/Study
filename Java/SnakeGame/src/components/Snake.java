package components;

import pages.Game;

import javax.swing.*;
import java.awt.*;
import java.util.Objects;


public class Snake {


    public static int y = 10;
    public static int x = 8;
    public static int lenSnake = 3;

    public static String direction = "Right";

    Snake(){

        Timer timer = new Timer(500, e -> {
            if ((y+1 > 21 || y -1 < 0 ) || (x+1 >20 || x -1 < 0 )){
                GameFrame.end = true;
            }

            if (Squares.squares[y][x] != null){
                if (Squares.squares[y][x].getBackground() == Color.red){lenSnake+=1;}
            }
            System.out.println(lenSnake);
            if (direction.equals("Right") && (x+1 <20 && x -1 > 0 )) {
                Squares.squarestime[y][x + 1] = lenSnake;
                if (Squares.squares[y][x+1].getBackground() == Color.red){lenSnake+=1;}
            } else if (direction.equals("Left") && (x+1 <20 && x -1 > 0 )) {
                Squares.squarestime[y][x - 1] = lenSnake;
            }
            if (direction.equals("Up") && (y+1 < 21 && y -1 > 0 )) {
                Squares.squarestime[y - 1][x] = lenSnake;
            } else if (direction.equals("Down") && (y+1 < 21 && y -1 > 0 )) {
                Squares.squarestime[y + 1][x] = lenSnake;
                if (Squares.squares[y +1][x].getBackground() == Color.red){lenSnake+=1;}
            }

            for (int j = 0; j <= lenSnake; j++) {
                for (int i = 0; i <= lenSnake; i++) {
                    if ((y + j > 21 || y - j < 0) || (x + i > 20 || x - i < 0)) {
                        continue;
                    }


                    JLabel newsquare = new JLabel();
                    newsquare.setBorder(BorderFactory.createLineBorder(Color.BLACK, 1));
                    newsquare.setBackground(Color.GREEN);
                    newsquare.setOpaque(true);
                    newsquare.setVisible(true);
                    Squares.squares[y][x] = newsquare;
                    if ((y + j < 21 && y - j > 0)&&(x + i < 20 && x - i > 0)) {
                        if(Squares.squarestime[y + j][x + i] > 0 ){Squares.squares[y + j][x + i] = newsquare;}
                        else if (Squares.squarestime[y - j][x - i] > 0){ Squares.squares[y - j][x - i] = newsquare;}
                    }

                }

            }
            switch (direction) {
                case "Right" -> x++;
                case "Left" -> x--;
                case "Up" -> y--;
                case "Down" -> y++;
            }
        });
        timer.setInitialDelay(2600);
        timer.start();
    }

}

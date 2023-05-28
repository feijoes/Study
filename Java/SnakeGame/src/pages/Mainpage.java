package pages;

import components.MainPageFrame;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Mainpage implements ActionListener {
    MainPageFrame myframe = new MainPageFrame();
    public Mainpage(){
        myframe.setButtonListenert(this);

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == myframe.getButton()){
            myframe.dispose();
            new Game();
        }
    }
}

package components;

import javax.swing.*;
import java.awt.*;


public class CountDown extends JPanel {
    JLabel label;
    Timer timer;
    int count = 5;
    public CountDown() {
        label = new JLabel("...");
        label.setFocusable(false);
        label.setFont(new Font(label.getFont().getName(), label.getFont().getStyle(), 40));
        setLayout(new GridBagLayout());
        add(label);
        timer = new Timer(500, e -> {
            count--;
            if (count >= 0) {
                label.setText(Integer.toString(count));
            } else {
                this.removeAll();
                this.revalidate();
                this.repaint();
                this.setVisible(false);
            }
        });
        timer.setInitialDelay(100);
        timer.start();

    }
    @Override
    public Dimension getPreferredSize() {
        return new Dimension(1, 1);
    }
    }


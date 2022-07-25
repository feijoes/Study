import java.util.Timer;
import java.util.TimerTask;
public class timerTask {
    public static void main(String[] args)  {
        Timer timer =  new Timer();
        TimerTask task = new TimerTask() {
            @Override
            public void run(){
                System.out.println("Time completed");
            }
        };
        timer.schedule(task, 1000);
    }
}

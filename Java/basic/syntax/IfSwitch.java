import java.util.Scanner;
public class IfSwitch {
    public static void main(String[] args) {
        Scanner scanner =  new Scanner(System.in);

        System.out.println("What is your age: ");
        int age = scanner.nextInt();

        if (age>=18){
            System.out.println("You are an adult!");
        }
        else if (age>=13){
            System.out.println("You are a Teenager!");
        }
        else{
            System.out.println(" You are an kid!");
        }
        System.out.println("What day is: ");
        String day = scanner.nextLine();

        switch(day){
            case "Sunday": System.out.println("today is Sunday");
            break;
            case "Monday": System.out.println("today is Monday");
            break;
            default:System.out.println("today is not Monday or Sunday");
        }
        scanner.close();
    }
}

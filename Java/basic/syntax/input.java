import java.util.Scanner;

public class input {
    public static void main(String args[]) {

        /* INPUT IN JAVA */
        Scanner scanner = new Scanner(System.in);
        System.out.println("What is your name ");
        String name = scanner.nextLine();
        scanner.close();
        System.out.println("YOUr name is "+name);
    }
}


import java.util.Scanner;

public class math {
    public static void main(String[] args){
        double a = 3.14;
        double b = 10;
        System.out.println(Math.min(a,b));  
        System.out.println(Math.round(a));  
        System.out.println(Math.abs(a));  
        System.out.println(Math.max(a,b));
        System.out.println(Math.ceil(a));


        double x,y,z;
        
        Scanner scanner =  new Scanner(System.in);

        System.out.println("Enter side x: ");
        x =  scanner.nextDouble();
        System.out.println("Enter side y: ");
        y =  scanner.nextDouble();
        z =Math.sqrt((x*x)+(y*y));

        System.out.println("The hypotenuse is: "+z);
        scanner.close();



    };
};

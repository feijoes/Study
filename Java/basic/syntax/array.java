import java.util.Arrays;
public class array {
    public static void main(String[] args) {
        // 1d array
        String[] cars = {"Camaro","Corvette","Tesla"};
        
        cars[0] = "Mustang";

        System.out.println(Arrays.toString(cars));

        for(int i=0; i<cars.length ;i++){
            System.out.println(cars[i]);
        }

        // 2d array

        String[][] cards2d = { 
            {"car1","car1","car1"},
            {"car2","car2","car2"}
        };

        for (int i=0;i < cards2d.length;i++){
            for (int j=0;j < cards2d[i].length;j++){
                System.out.print(cards2d[i][j] + " ");
            }
            System.out.println();
        }
        // for each
        for (String j: cars){
            System.out.println(j);
        };
    };
}

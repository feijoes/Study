import java.util.ArrayList;

public class arraylist {
    public static void main(String[] args) {

        ArrayList<String> food = new ArrayList<String>();
        
        food.add("pizza");
        food.add("chips");
        food.set(1,"sushi");
        for (int i=0;i<food.size();i++){ 
            System.out.println(food.get(i));
        };

        ArrayList<ArrayList<String>> groceryList = new ArrayList<ArrayList<String>>();
        
        ArrayList<String> produceList = new ArrayList<String>();

        produceList.add("tomatoes");
        produceList.add("potatoes");

        groceryList.add(produceList);

        System.out.println(groceryList);
        
    }
}

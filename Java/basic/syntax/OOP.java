public class OOP {
    public static void main(String[] args) {
        Car myCar = new Car(100);
        

        System.out.println(myCar.getSpeed());
        //myCar.drive();
        //myCar.go();


        Human human1 = new Human("Pedro",18,70);
        Human human2 = new Human(human1);

        //System.out.println(human1.weight);
        //human2.eat();
        //System.out.println(human2.weight);
        //System.out.println(human1);


       // human1.parkcar(myCar);
       // System.out.println(Human.numberOfHumans);
       // Human.Population();
    }
}
class Car extends Vehicle{
    String make= "Chevrolet";
    String model= "Corvette";
    int year = 2020;
    double price = 500000.0;
    Car(double speed){
        super(speed);
    }
    
    void drive(){
        System.out.println("You drive the car");
    }
    
}
class Human {
    String name;
    int age;
    double weight;
    static int numberOfHumans;

    // def __init__ in python
    Human(String name,int age, double weight){
        this.name = name;
        this.age = age;
        this.weight = weight;
        numberOfHumans++;
    }
    Human(Human x){
        this.copy(x);
    }


    void parkcar(Car car){
        System.out.println("The "+car.model + " is parked in the "+ name +" garage");
    }

    static void Population(){
        System.out.println("The number of people in the world are: " + numberOfHumans);
    }
    // def __str__ in python
    public String toString(){
        return name+ " " + age + " "+ weight;
    }
    void eat(){
        System.out.println(this.name + " is eating");
        this.weight++;
    }
    public void copy(Human x){
        this.name = x.name;
        this.age = x.age;
        this.weight = x.weight;
    }

}

class Vehicle{
    private double speed;
    
    Vehicle(double speed){
        this.speed = speed;
    }
    void go(){
        System.out.println("This vehicle is moving");
    };
    public double getSpeed(){
        return speed;
    }
}
// static , class props
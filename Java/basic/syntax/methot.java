public class methot {
    public static void main(String[] args) {
        Print("Bro",2);
        System.out.println(add(10, 20));
        System.out.println(add(10, 10,20));
    }

    static void Print(String name,int age){
        System.out.println("hello " +name);
        System.out.println("You are " +age);
    };

    static int add(int x, int y) {
        return x + y;
    }
    static int add(int x, int y,int z) {
        return x + y+ z;
    }

}

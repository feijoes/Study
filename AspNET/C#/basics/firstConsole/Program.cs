using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {	
    Console.Write("Enter your name: ");    
	string name = Console.ReadLine();
    Console.Write("Enter your age: ");    
	int age = Convert.ToInt32(Console.ReadLine());
	
    Console.WriteLine("Your name is " + name + "your age is "+age);  
    }
}
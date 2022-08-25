// See https://aka.ms/new-console-template for more information
using System;

public class Program
{
    public static void Main()
    {
        //List<int> list = SumN();
        //Console.WriteLine("[{0}]",string.Join<int>(",", list));
        //Guessing_Word();
        ClassTest.Car car1 = new ClassTest.Car("Car");

        Console.WriteLine(car1.Name);

    }

    static List<int> SumN()
    {
        return new List<int>(Enumerable.Range(0, 10));
    }

    static void Guessing_Word()
    {
        Random r = new Random();
        string[] words = { "man", "rat", "cow", "chicken" };
        int guessCount = 0;
        int guessLimit = 3;
        string SecretWord = words[r.Next(0, words.Length - 1)];
        String? guess;
        
        do
        {
            Console.Write("Enter guess: ");
            guess = Console.ReadLine();
            guessCount++;
        } while (guess != SecretWord && guessLimit > guessCount);
        if (guessCount == guessLimit)
        {
            Console.WriteLine("you lose");
        }
        else
        {
            Console.WriteLine("you WIN");
        }


    }
}
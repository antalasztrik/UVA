using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UVA
{
    class Program
    {
        static String word;
        static String guess;
        static List<char> letters;
        static int count;

        public static void Main(String[] args)
        {
            int round, result;
            while ((round = Int32.Parse(Console.ReadLine())) != -1)
            {
                word = Console.ReadLine();
                guess = Console.ReadLine();
                init();
                result = Solve(guess);
                Print(result, round);
            }
        }

        private static void Print(int result, int round)
        {
            Console.WriteLine("Round " + round);
            if (result == 1)
                Console.WriteLine("You win.");

            if (result == 0)
                Console.WriteLine("You chickened out.");

            if (result == -1)
                Console.WriteLine("You lose.");
        }

        private static int Solve(String g)
        {
            int stroke = 0, i;
            List<char> alreadyGuessed = new List<char>();

            for (i = 0; i < guess.Length; i++)
            {
                if (letters.Contains(guess[i]))
                {
                    letters.Remove(guess[i]);
                    alreadyGuessed.Add(guess[i]);

                    if (letters.Count == 0)
                        return 1;
                }
                else
                {
                    if (!alreadyGuessed.Contains(guess[i]))
                    {
                        stroke++;
                        alreadyGuessed.Add(guess[i]);
                    }

                    if (stroke == 7)
                        return -1;
                }
            }

            return 0;
        }

        private static void init()
        {
            int i;
            letters = new List<char>();
            for (i = 0, count = 0; i < word.Length; i++)
            {
                if (!letters.Contains(word[i]))
                {
                    letters.Add(word[i]);
                    count++;
                }
            }
        }
    }
}

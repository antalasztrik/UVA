using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UVA
{
    class Program
    {
        static int set = 0;
        static int[,] deck = new int[2, 52];
        static int[,] shuffles = new int[100, 52];
        static String[] names = new String[] { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
        static String[] color = new String[] { "Clubs", "Diamonds", "Hearts", "Spades" };
        public static void Main(String[] args)
        {
            int N;
            N = Int32.Parse(Console.ReadLine());
            Console.ReadLine();
            while (N-- != 0)
            {
                Init();
                Get_shuffles();
                Solve();
                Print();
                if (N > 0)
                    Console.WriteLine();
            }
        }

        private static void Print()
        {
            for (int i = 0; i < 52; i++){
                Console.WriteLine(names[(deck[set, i]) % 13] + " of " + color[(deck[set, i] - 1) / 13]);
            }
        }

        private static void Solve()
        {
            String numShuffle;
            while((numShuffle = Console.ReadLine()) != null && !numShuffle.Equals(""))
            {
                Shuffle(Int32.Parse(numShuffle) - 1);
            }
        }

        private static void Shuffle(int n)
        {
            int i;
            for (i = 0; i < 52; i++)
            {
                if (shuffles[n, i] == 0)
                    Console.WriteLine(n + " " + i);
                deck[1 - set, i] = deck[set, shuffles[n, i] - 1];
            }
            set = 1 - set;
        }

        private static void Get_shuffles()
        {
            int i, j, n, cardCounter;
            n = Int32.Parse(Console.ReadLine());
            for (i = 0; i < n; i++)
            {
                cardCounter = 0;
                while (cardCounter != 52)
                {
                    String[] x = Console.ReadLine().Split(' ');
                    for (j = cardCounter; j < cardCounter + x.Length; j++)
                    {
                        shuffles[i, j] = Int32.Parse(x[j - cardCounter]);
                    }
                    cardCounter += x.Length;
                }
            }
        }

        private static void Init()
        {
            int i;
            for (i = 0; i < 52; i++)
                deck[0, i] = deck[1, i] = i + 1;
        }
    }
}

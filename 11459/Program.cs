using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UVA
{
    class Program
    {
        static int[] players = new int[1000000];
        public static void Main(String[] args)
        {
            int N, a, b, c, i, roll, current;
            bool winner;
            N = Int32.Parse(Console.ReadLine());
            while (N > 0)
            {
                winner = false;
                String[] data = Console.ReadLine().Split(' ');

                a = Int32.Parse(data[0]);
                b = Int32.Parse(data[1]);
                c = Int32.Parse(data[2]);

                int[] step = new int[101];

                for (i = 0; i < a; i++)
                    players[i] = 1;

                for (i = 0; i < 101; i++)
                    step[i] = i;

                for (i = 0; i < b; i++)
                {
                    String[] snakeLadder = Console.ReadLine().Split(' ');
                    step[Int32.Parse(snakeLadder[0])] = Int32.Parse(snakeLadder[1]);
                }

                for (i = 0; i < c; i++)
                {
                    roll = Int32.Parse(Console.ReadLine());
                    if (!winner)
                    {
                        current = players[i % a] + roll;
                        if (step[current] < 100)
                        {
                            players[i % a] = step[current];
                        }
                        else
                        {
                            players[i % a] = 100;
                            winner = true;
                        }
                    }
                }

                for (i = 0; i < a; i++)
                {
                    Console.WriteLine("Position of player " + (i + 1) + " is " + players[i] + ".");
                }
                N--;
            }
        }
    }
}

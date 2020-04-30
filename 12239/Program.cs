using System;

namespace UVA
{
    class Program
    {
        static void Main(string[] args)
        {
            int N, B, i, j;
            Boolean good;
            String[] data = Console.ReadLine().Split(" ");
            String balls;
            N = Convert.ToInt32(data[0]);
            B = Convert.ToInt32(data[1]);
            while (N != 0 && B != 0)
            {
                good = true;
                int[] t = new int[B];
                int[] sum = new int[N + 1];
                balls = Console.ReadLine();

                for (i = 0; i < B; i++)
                    t[i] = Convert.ToInt32(balls.Split(" ")[i]);

                for (i = 0; i < B; i++)
                    for (j = 0; j < B; j++)
                        sum[Math.Abs(t[i] - t[j])]++;

                for (i = 0; i < N + 1; i++)
                    if (sum[i] == 0)
                        good = false;

                Console.WriteLine(good ? "Y" : "N");

                data = Console.ReadLine().Split(" ");
                N = Convert.ToInt32(data[0]);
                B = Convert.ToInt32(data[1]);
            }
        }
    }
}

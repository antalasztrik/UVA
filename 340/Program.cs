using System;

namespace UVA
{
    class Program
    {
        static private int[] t = new int[1000];
        static private int N, game = 1;
        static private string line;
        static void Main(string[] args)
        {
            int i;
            while ((line = Console.ReadLine()) != null && line != "")
            {
                N = Convert.ToInt32(line);
                if (N == 0)
                    break;

                Console.WriteLine("Game " +  game++ + ":");
                String[] items;
                items = Console.ReadLine().Split(" ");
                for (i = 0; i < N; i++)
                {
                    t[i] = Convert.ToInt32(items[i]);
                }

                Solve();
            }
        }


        static void Solve()
        {
            int strong, weak, i, j;
            int[] arr = new int[N];
            int[] copy = new int[N];
            while (true)
            {
                strong = weak = 0;
                String[] items;
                items = Console.ReadLine().Split(" ");
                for (i = 0; i < N; i++)
                {
                    arr[i] = Convert.ToInt32(items[i]);
                    copy[i] = t[i];
                }

                if (arr[0] == 0)
                    break;

                for (i = 0; i < N; i++)
                {
                    if (arr[i] == copy[i])
                    {
                        strong++;
                        copy[i] = arr[i] = 0;
                    }
                }

                for (i = 0; i < N; i++)
                {
                    for (j = 0; j < N; j++)
                    {
                        if (arr[i] == copy[j] && arr[i] > 0)
                        {
                            weak++;
                            copy[j] = 0;
                            break;
                        }
                    }
                }

                Console.WriteLine("    (" + strong + "," + weak + ")");
            }
        }
    }
}


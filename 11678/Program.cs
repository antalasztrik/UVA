using System;

namespace UVA
{
    class Program
    {
        static int Anum, Bnum;
        static int[] adeck;
        static int[] bdeck;
        static void Main(string[] args)
        {
            int A, B, result;
            String[] cardsNum = Console.ReadLine().Split(" ");
            while ((A = Convert.ToInt32(cardsNum[0])) > 0 && (B = Convert.ToInt32(cardsNum[1])) > 0)
            {
                init();
                input(A, B);
                result = solve();
                Console.WriteLine(result);
                cardsNum = Console.ReadLine().Split(" ");
            }
        }

        private static int solve()
        {
            int i;
            for (i = 0; i < 100000; i++)
            {
                if (adeck[i] != 0 && bdeck[i] == 0)
                    Anum++;

                if (adeck[i] == 0 && bdeck[i] != 0)
                    Bnum++;
            }

            return Anum < Bnum ? Anum : Bnum;
        }

        private static void input(int A, int B)
        {
            int i, num;
            String[] cards = Console.ReadLine().Split(" ");

            for (i = 0; i < A; i++)
            {
                num = Convert.ToInt32(cards[i]);
                adeck[num]++;
            }

            cards = Console.ReadLine().Split(" ");

            for (i = 0; i < B; i++)
            {
                num = Convert.ToInt32(cards[i]);
                bdeck[num]++;
            }
        }

        private static void init()
        {
            Anum = Bnum = 0;
            adeck = new int[100000];
            bdeck = new int[100000];
        }
    }
}

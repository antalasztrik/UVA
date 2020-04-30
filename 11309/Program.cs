using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UVA
{

    class Program
    {
        static int[] palindrome = new int[2360];
        public static void Main(String[] args)
        {
            Gen();
            int n, x, z;
            String s;
            n = Int32.Parse(Console.ReadLine());
            while (n > 0)
            {
                s = Console.ReadLine();
                x = 1000 * (s[0] - 48) + 100 * (s[1] - 48) + 10 * (s[3] - 48) + (s[4] - 48);
                z = Solve(x);
                String hour = Convert.ToString(z / 100);
                String minute = Convert.ToString(z % 100);
                Console.WriteLine(hour.PadLeft(2, '0') + ":" + minute.PadLeft(2, '0') + "\n");
                n--;
            }
        }

        private static int Solve(int x)
        {
            while (palindrome[++x % 2360] != 1) ;
            return x % 2360;
        }

        private static bool Palind(int x)
        {
            int b = 0, e;
            String s = x + "";
            e = s.Length - 1;

            if (x % 100 >= 60)
                return false;

            while (e > b)
            {
                if (s[b++] != s[e--])
                    return false;
            }

            return true;
        }

        private static void Gen()
        {
            int i;
            for (i = 0; i < 2359; i++)
                if (Palind(i))
                    palindrome[i] = 1;
        }
    }

}

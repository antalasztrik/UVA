using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UVA
{
    public class Program
    {
        public static void Main(String[] args)
        {
            int N;
            N = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < N; i++)
            {
                String cards = Console.ReadLine();
                Console.WriteLine("Case " + (i + 1) + ": " + cards[96] + cards[97]);
            }
        }
    }
}

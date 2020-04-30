using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UVA
{
    class Program
    {
        public static void Main(String[] args)
        {
            int C, T, N, bishopRow, bishopColumn, squareRow, squareColumn, result;
            C = Int32.Parse(Console.ReadLine());
            while (C > 0)
            {
                Console.ReadLine();
                T = Int32.Parse(Console.ReadLine());
                N = Int32.Parse(Console.ReadLine());
                while (T > 0)
                {
                    List<string> positions = Console.ReadLine().Split(new[] { "  " }, StringSplitOptions.RemoveEmptyEntries)
                    .Select(s => s.Trim())
                    .ToList();

                    bishopRow = Int32.Parse(positions[0]);
                    bishopColumn = Int32.Parse(positions[1]);
                    squareRow = Int32.Parse(positions[2]);
                    squareColumn = Int32.Parse(positions[3]);
                    result = Solve(Math.Abs(bishopRow - squareRow), Math.Abs(bishopColumn - squareColumn));
                    Print(result);
                    T--;
                }
                C--;
            }
        }

        private static void Print(int result)
        {
            if (result != -1)
            {
                Console.WriteLine(result);
            }
            else
            {
                Console.WriteLine("no move");
            }
        }

        private static int Solve(int rowDiff, int columnDiff)
        {
            if (rowDiff == 0 && columnDiff == 0)
            {
                return 0;
            }
            if ((rowDiff % 2) == (columnDiff % 2))
            {
                if (rowDiff == columnDiff)
                {
                    return 1;
                }
                return 2;
            }
            return -1;
        }
    }
}

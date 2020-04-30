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
            int rolls, top, north, west, temporary;
            String command;
            while ((rolls = Int32.Parse(Console.ReadLine())) != 0)
            {
                top = 1;
                north = 2;
                west = 3;

                while (rolls > 0)
                {
                    command = Console.ReadLine();

                    if (command.Equals("north"))
                    {
                        temporary = top;
                        top = 7 - north;
                        north = temporary;
                    }

                    if (command.Equals("west"))
                    {
                        temporary = top;
                        top = 7 - west;
                        west = temporary;
                    }

                    if (command.Equals("south"))
                    {
                        temporary = top;
                        top = north;
                        north = 7 - temporary;
                    }

                    if (command.Equals("east"))
                    {
                        temporary = top;
                        top = west;
                        west = 7 - temporary;
                    }

                    rolls--;
                }

                Console.WriteLine(top);
            }
        }
    }
}
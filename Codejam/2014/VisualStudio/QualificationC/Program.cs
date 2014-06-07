using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace QualificationC
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader input = new StreamReader("D-test.in");
            //StreamWriter output = new StreamWriter("D-test.out");

            StreamReader input = new StreamReader("D-large.in");
            StreamWriter output = new StreamWriter("D-large.out");
            //StreamReader input = new StreamReader("D-small-attempt0.in");
            //StreamWriter output = new StreamWriter("D-small-attempt0.out");

            Console.WriteLine("Read, Write Files Prepared!");
            int T = int.Parse(input.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                int[] data = input.ReadLine().Split().Select(int.Parse).ToArray();
                string ret = solve(data[0], data[1], data[2]);
            }
            input.Close();
            output.Close();
            Console.WriteLine("Done");
            Console.Read();
        }

        private static string solve(int R, int C, int M)
        {
            if (R > C)
            {
                string tmp = solve(C, R, M);
                if (tmp == "Impossible")
                {
                    return tmp;
                }
                else
                {
                    
                }
            }

        }
    }
}

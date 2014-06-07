using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace GoogleCodejam
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader input = new StreamReader("B-large.in");
            StreamWriter output = new StreamWriter("B-large.out");
            //StreamReader input = new StreamReader("B-small-attempt0.in");
            //StreamWriter output = new StreamWriter("B-small-attempt0.out1");
  
            Console.WriteLine("Read, Write Files Prepared!");
            string line;
            line = input.ReadLine();
            int T = int.Parse(line);
            for (int t = 1; t <= T; t++)
            {
                line = input.ReadLine();
                string[] splits = line.Split(' ');
                double ret = solve(double.Parse(splits[0]), double.Parse(splits[1]), double.Parse(splits[2]));
                output.WriteLine("Case #" + t + ": " + ret);
            }
            input.Close();
            output.Close();
            Console.WriteLine("Done");
            Console.Read();
        }

        private static double solve(double C, double F, double X)
        {
            if (C >= X)
            {
                return X / 2;
            }
            else
            {
                int low = 0;
                int high = 1000000;
                int mid;
                while (low <= high)
                {
                    mid=(low+high)/2;
                    if (C / (2 + mid * F) + X / (2 + (mid + 1) * F) >= X / (2 + mid * F))
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                mid = low;
                Console.WriteLine(mid);
                double ret = 0;
                for (double i = 0; i < mid; i++)
                {
                    ret += C / (2.0 + i * F);
                }
                ret += X / (2.0 + mid * F);
                return ret;
            }
        }
    }
}

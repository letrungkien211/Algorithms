using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Round1A2
{
    class Program
    {
        static void Main(string[] args)
        {
            string label = "B";
            int labeln = 0;
            string dirname = @"C:\Users\trule\Downloads\";
            string[] filename = new string[] { "test", "small-attempt0", "large" };
            string[] infile = (from f in filename select label + "-" + f + ".in").ToArray();
            string[] outfile = (from f in filename select label + "-" + f + ".out").ToArray();

            StreamReader input = new StreamReader(dirname + infile[labeln]);
            StreamWriter output = new StreamWriter(dirname + outfile[labeln]);

            Console.WriteLine(output.ToString());
            int T = int.Parse(input.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                //string result = process();
                //output.WriteLine("Case #{0}: {1}", t, result);   
            }
            input.Close();
            output.Close();
            Console.WriteLine("Done");
            Console.Read();
        }
    }
}

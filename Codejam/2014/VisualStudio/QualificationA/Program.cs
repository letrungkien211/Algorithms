using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace QualificationA
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader input = new StreamReader("A-test.in");
            //StreamWriter output = new StreamWriter("test.out");
            
            //StreamReader input = new StreamReader("B-large.in");
            //StreamWriter output = new StreamWriter("B-large.out");
            StreamReader input = new StreamReader("A-small-attempt0.in");
            StreamWriter output = new StreamWriter("A-small-attempt0.out1");

            Console.WriteLine("Read, Write Files Prepared!");
            string line;            
            int T = int.Parse(input.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] row1=null, row2=null;
                int choice = int.Parse(input.ReadLine());                
                for (int i = 1; i <= 4; i++)
                {
                    if (i == choice)
                    {
                        row1 = input.ReadLine().Split();
                    }
                    else
                    {
                        input.ReadLine();
                    }
                }

                choice = int.Parse(input.ReadLine());
                for (int i = 1; i <= 4; i++)
                {
                    if (i == choice)
                    {
                        row2 = input.ReadLine().Split();
                    }
                    else
                    {
                        input.ReadLine();
                    }
                }

                string[] inter = row1.Intersect(row2).ToArray();
                string ret;
                if (inter.Length == 1)
                {
                    ret = inter[0];
                }
                else if (inter.Length == 0)
                {
                    ret = "Volunteer cheated!";
                }
                else
                {
                    ret = "Bad magician!";
                }

                output.WriteLine("Case #" + t + ": " + ret);
            }
            input.Close();
            output.Close();
            Console.WriteLine("Done");
            Console.Read();
        }
    }
}

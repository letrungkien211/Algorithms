using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace QualificationD
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
                int N = int.Parse(input.ReadLine());
                List<double> A = input.ReadLine().Split().Select(double.Parse).ToList();
                List<double> B = input.ReadLine().Split().Select(double.Parse).ToList();

                Tuple<int, int> ret = solve(N, A, B);
                output.WriteLine("Case #" + t + ": " + ret.Item1 + " " + ret.Item2);
            }
            input.Close();
            output.Close();
            Console.WriteLine("Done");
            Console.Read();
        }

        private static Tuple<int, int> solve(int N, List<double> A, List<double> B)
        {
            A.Sort();
            B.Sort();

            return new Tuple<int, int>(solve1(N, A, B), solve2(N, A, B));

        }

        private static int solve2(int N, List<double> A, List<double> B)
        {
            int i = 0, j = 0;            
            int ret =0;
            while (i < N && j < N)
            {
                if (A[i] < B[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    j++;
                    ret++;
                }         
            }

            return ret;
        }

        private static int solve1(int N, List<double> A, List<double> B)
        {
            int i = 0, j = 0, k = N - 1;
            int ret = 0;

            while (i < N && j <= k)
            {
                if (A[i] < B[j])
                {
                    i++;
                    k--;
                }
                else
                {
                    ret++;
                    i++;
                    j++;
                }
            }

            return ret;
        }


    }
}

using System;



public class Class1
{
    public Class1()
    {
        string label = "A";
        int labeln = 0;
        string dirname = @"C:\Users\trule\Downloads\";
        string[] filename = new string[] { "-test", "-small-attempt0", "-large" };        
        string[] infile = from f in filename select label+"-" + f + ".in";
        string[] outfile = from f in filename select label+"-" + f + ".out";

        StreamReader input = new StreamReader(dirname+infile[labeln]);
        StreamWriter output = new StreamWriter(dirname+outfile[labeln]);
        
        int T = int.Parse(input.ReadLine());
        for (int t = 1; t <= T; t++)
        {
            
            
        }
        input.Close();
        output.Close();
        Console.WriteLine("Done");
        Console.Read();

    }
}

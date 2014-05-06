using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PacmanAI
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int i = 0; i < 1000; i++)
                System.Console.WriteLine("Hi James");

            System.IO.StreamReader s1 = new System.IO.StreamReader("pacman.state");
            char[] buffer = new char[100];
            s1.ReadBlock(buffer, 0, 100);
            s1.Close();
        }
    }
}

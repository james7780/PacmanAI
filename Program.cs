// Pacman AI
// - Game theory AI to calculate next move for pacman for a given maze state
// Rules:
// - Pacman may move in any direction that has a space or a pill
// - Pacman must move in a path that maximises points (pills eaten)
// - Pacman must avoid or eat the enemy pacman object
//
// TODO : Also make a "game runner" app that runs 2 AI's against each other

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

// Topic7_ClassNotes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "Function01.h"
#include "NonlinearSolver01.h"

using namespace std;
using namespace fre;


int main()
{
    double Acc1 = 0.0001;
    double LEnd1 = 0.0, REnd1 = 2.0;
    double Tgt1 = 0.0, Guess1 = 1.0;

    NonlinearSolver solver(Tgt1, LEnd1, REnd1, Acc1, Guess1);
    cout << "Root of F1 by Bisect: " << fixed << setprecision(4) 
        << solver.SolveByBisect(F1) << endl;
    cout << "Root of F1 by Newton-Raphson: " << fixed << setprecision(4) 
        << solver.SolveByNR(F1, DF1) << endl << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

/*
Non-Linear Solver 01

Root of F1 by Bisect : 1.4142
Root of F1 by Newton - Raphson : 1.4142
*/

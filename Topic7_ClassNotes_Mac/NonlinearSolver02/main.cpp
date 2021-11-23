//
//  main.cpp
//  EurCall
//
//  Created by Hanji Gu on 11/15/21.
//

#include <iostream>
#include <iomanip>
#include "Function02.hpp"
#include "NonlinearSolver02.hpp"
//#include "EurCall.hpp"

using namespace std;
using namespace fre;

int main() {
//    double S0 = 100.0;
//    double r = 0.1;
//    double T = 1.0;
//    double K = 100.0;
//
//    Intermediary Call(S0, r, T, K);

    double Acc1 = 0.0001;
    double LEnd1 = 0.0;
    double REnd1 = 2.0;
    double Tgt1 = 0.0;
    double Guess1 = 1.0;

    NonlinearSolver solver(Tgt1, LEnd1, REnd1, Acc1, Guess1);
    F1 myF1;
    cout << "Root of F1 by Bisect: " << fixed << setprecision(4)
        << solver.SolveByBisect(&myF1) << endl;
    cout << "Implied Volatilty by Newton-Raphson: " << fixed << setprecision(4)
        << solver.SolveByNR(&myF1) << endl;
    
    double Acc2 = 0.0001;
    double LEnd2 = 0.0;
    double REnd2 = 4.0;
    double Tgt2 = 0.0;
    double Guess2 = 3.0;
    
    solver.UpdateSolver(Tgt2, LEnd2, REnd2, Acc2, Guess2);
    F2 myF2(10.0);

    cout << "Root of F1 by Bisect: " << fixed << setprecision(4)
        << solver.SolveByBisect(&myF2) << endl;
    cout << "Implied Volatilty by Newton-Raphson: " << fixed << setprecision(4)
        << solver.SolveByNR(&myF2) << endl;
    
    return 0;
}

/*
 Implied Volatility by Bisect: 0.1784
 Implied Volatilty by Newton-Raphson: 0.1784
 */

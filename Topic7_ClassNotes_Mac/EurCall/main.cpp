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
#include "EurCall.hpp"

using namespace std;
using namespace fre;

int main() {
    double S0 = 100.0;
    double r = 0.1;
    double T = 1.0;
    double K = 100.0;

    Intermediary Call(S0, r, T, K);

    double Acc = 0.0001;
    double LEnd = 0.01;
    double REnd = 1.0;
    double Tgt = 12.56;
    double Guess = 0.23;

    NonlinearSolver solver(Tgt, LEnd, REnd, Acc, Guess);

    cout << "Implied Volatility by Bisect: " << fixed << setprecision(4)
        << solver.SolveByBisect(&Call) << endl;
    cout << "Implied Volatilty by Newton-Raphson: " << fixed << setprecision(4)
        << solver.SolveByNR(&Call) << endl;
    return 0;
}

/*
 Implied Volatility by Bisect: 0.1784
 Implied Volatilty by Newton-Raphson: 0.1784
 */

// HW5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "BinomialTreeModel02.h"
#include "Option05.h"
#include "DoubleDigitOpt.h"

using namespace std;
using namespace fre;

int main()
{
    int N = 8;
    double U = 1.15125, D = 0.86862, R = 1.00545;
    double S0 = 106.00, K1 = 100, K2 = 110;

    BinomialTreeModel Model(S0, U, D, R);
    
    DoubDigitOpt doubDigitOpt(N, K1, K2);
    OptionCalculation doubleDigitOptCalc(&doubDigitOpt);
    cout << "European double digit option price = "
        << fixed << setprecision(2) << doubleDigitOptCalc.PriceByCRR(Model) << endl;
    
    Strangle strangle(N, K1, K2);
    OptionCalculation strangeleCalc(&strangle);
    cout << "European Strangle price = "
        << fixed << setprecision(2) << strangeleCalc.PriceByCRR(Model) << endl;

    Butterfly butterfly(N, K1, K2);
    OptionCalculation butterflyCalc(&butterfly);
    cout << "European Butterfly price = "
        << fixed << setprecision(2) << butterflyCalc.PriceByCRR(Model) << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu



/*
European double digit option price = 0.26
European Strangle price = 28.39
European Butterfly price = 1.04
*/
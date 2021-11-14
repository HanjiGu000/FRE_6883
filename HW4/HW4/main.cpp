// HW4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "BinomialTreeModel02.h"
#include "Option05.h"

using namespace std;
using namespace fre;

int main()
{
    int N = 8;
    double U = 1.15125, D = 0.86862, R = 1.00545;
    double S0 = 106.00, K = 100.00;
    double K1 = 100, K2 = 110;

    BinomialTreeModel Model(S0, U, D, R);
    
    Call call(N, K);
    OptionCalculation callCalculation(&call);
    cout << "European call = " 
        << fixed << setprecision(2) << callCalculation.PriceByCRR(Model) << endl;

    Put put(N, K);
    OptionCalculation putCalculation(&put);
    cout << "European put = " 
        << fixed << setprecision(2) << putCalculation.PriceByCRR(Model) << endl;

    BullSpread bullspread(N, K1, K2);
    OptionCalculation bullspreadCalculation(&bullspread);
    cout << "BullSpread with K1(100) and K2(110) = " 
        << fixed << setprecision(2) << bullspreadCalculation.PriceByCRR(Model) << endl;
    
    BearSpread bearspread(N, K1, K2);
    OptionCalculation bearspreadCalculation(&bearspread);
    cout << "BearSpread with K1(100) and K2(110) = " 
        << fixed << setprecision(2) << bearspreadCalculation.PriceByCRR(Model) << endl;
    
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu



/*
European call = 21.68
European put = 11.43
BullSpread with K1(100) and K2(110) = 4.72
BearSpread with K1(100) and K2(110) = 4.86
*/
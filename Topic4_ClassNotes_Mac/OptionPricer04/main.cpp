//
//  main.cpp
//  OptionPricer04
//
//  Created by Hanji Gu on 11/21/21.
//

#include <iostream>
#include "BinomialTreeModel02.hpp"
#include "Option04.hpp"
#include <iostream>
#include <iomanip>

using namespace fre;
using namespace std;

int main() {
    int N = 8;
    double U = 1.15125;
    double D = 0.86862;
    double R = 1.00545;
    double S0 = 106.00;
    double K = 100.00;
    
    // static object, Model in stack
    BinomialTreeModel Model(S0, U, D, R);
    // dynamic object, pCall on heap
    Call * pCall = new Call(N, K);
    // static object, callCalculation in stack
    OptionCalculation callCalculation(pCall);
    
    cout << "European Call Option Price = " << fixed << setprecision(2)
         << callCalculation.PriceByCRR(Model) << endl;
    
    // dynamic allocated object delete first
    delete pCall;
    pCall = NULL;
    
    return 0;
    // optionCalculation destroyed
    // Model destroyed
}

/*
 European Call Option Price = 21.68
 */

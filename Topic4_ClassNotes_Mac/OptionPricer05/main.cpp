//
//  main.cpp
//  OptionPricer05
//
//  Created by Hanji Gu on 11/21/21.
//

#include <iostream>
#include <iomanip>
#include "Option05.hpp"
#include "BinomialTreeModel02.hpp"

using namespace std;
using namespace fre;

int main() {
    int N = 8;
    double U = 1.15125;
    double D = 0.86862;
    double R = 1.00545;
    double S0 = 106.00;
    double K = 100.00;
    
    BinomialTreeModel Model(S0, U, D, R);
    
    Call call(N, K);
    // associate address of call to EurOption * pOption in constructor
    OptionCalculation callCalculation(&call);
    cout << "European call = " << fixed << setprecision(2)
         << callCalculation.PriceByCRR(Model) << endl;
    
    Put put(N, K);
    OptionCalculation putCalculation(&put);
    cout << "European put = " << fixed << setprecision(2)
         << putCalculation.PriceByCRR(Model) << endl;
    return 0;
}


/*
 European call = 21.68
 European put = 11.43
 */

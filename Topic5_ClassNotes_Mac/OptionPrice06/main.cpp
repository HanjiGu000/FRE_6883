//
//  main.cpp
//  OptionPrice06
//
//  Created by Hanji Gu on 11/21/21.
//

#include <iostream>
#include "Option06.hpp"
#include "BinomialTreeModel02.hpp"
#include <iomanip>

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
    OptionCalculation callCalculation(&call);
    cout << "European Call Option Price = " << fixed << setprecision(2)
         << callCalculation.PriceByCRR(Model) << endl;
    
    Put put(N, K);
    OptionCalculation putCalculation(&put);
    cout << "European Call Option Price = " << fixed << setprecision(2)
         << putCalculation.PriceByCRR(Model) << endl;
    
    cout << "American Call Option Price = " << fixed << setprecision(2)
        << callCalculation.PriceBySnell(Model) << endl;

    cout << "American Call Option Price = " << fixed << setprecision(2)
        << putCalculation.PriceBySnell(Model) << endl;

    return 0;
}

/*
 European Call Option Price = 21.68
 European Call Option Price = 11.43
 American Call Option Price = 21.68
 American Call Option Price = 11.72
 Program ended with exit code: 0
 */

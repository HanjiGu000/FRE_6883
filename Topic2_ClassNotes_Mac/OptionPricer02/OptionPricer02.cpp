//
//  main.cpp
//  OptionPricer02
//
//  Created by Hanji Gu on 11/20/21.
//

#include <iostream>
#include "BinomialTreeModel.hpp"
#include "Options02.hpp"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace fre;

int main() {
    double S0 = 0.0;
    double U = 0.0;
    double D = 0.0;
    double R = 0.0;
    
    // GetInputData from BinomialTreeModel, call by reference
    if (GetInputData(S0, U, D, R) != 0)
    {
        return -1;
    }
    
    double K = 0.0;
    int N = 0;
    
    cout << "Enter Call Option Data" << endl;
    // GetInputData from Option02
    // Function overloading
    GetInputData(N, K);
    
    double * optionPrice = nullptr;
    optionPrice = PriceByCRR(S0, U, D, R, N, K, CallPayoff);
    cout << "European Call Option Price = " << fixed << setprecision(2)
         << optionPrice[0] << endl;
    
    optionPrice = PriceByCRR(S0, U, D, R, N, K, PutPayoff);
    cout << "European Put Option Price = " << fixed << setprecision(2)
         << optionPrice[0] << endl;
    
    
    delete [] optionPrice;
    optionPrice = NULL;
    return 0;
}

/*
 Enter S0: 106
 Enter U: 1.15125
 Enter D: 0.86862
 Enter R: 1.00545
 // int GetInput(S0, U, D, K)

 Input data checked
 There is no arbitrage

 Enter Call Option Data
 Enter steps to expiry N: 8
 Enter strike price K: 100

 European Call Option Price = 21.68
 European Put Option Price = 11.43
 Program ended with exit code: 0
 */

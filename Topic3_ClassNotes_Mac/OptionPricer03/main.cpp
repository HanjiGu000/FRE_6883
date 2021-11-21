//
//  main.cpp
//  OptionPricer03
//
//  Created by Hanji Gu on 11/21/21.
//

#include <iostream>
#include "BinomialTreeModel02.hpp"
#include "Option03.hpp"
#include <iostream>
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
    
    BinomialTreeModel BinModel(S0, U, D, R);
    if (BinModel.ValidateInputData() != 0) return -1;
    
    double * optionPrice = NULL;
    optionPrice = PriceByCRR(BinModel, N, K, CallPayoff);
    cout << "European Call Option Price = " << optionPrice[0] << endl;
    delete [] optionPrice;
    
    optionPrice = PriceByCRR(BinModel, N, K, PutPayoff);
    cout << "European Put Option Price = " << optionPrice[0] << endl;
    delete [] optionPrice;
    optionPrice = NULL;
    
    return 0;
}

/*
 Input data checked
 There is not arbitrage

 European Call Option Price = 21.6811
 European Put Option Price = 11.4261
 Program ended with exit code: 0
 */

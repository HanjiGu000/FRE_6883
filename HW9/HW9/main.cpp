//
//  main.cpp
//  main01
//
//  Created by Hanji Gu on 11/15/21.
//

#include <iostream>
#include "PathDepOption.hpp"

using namespace fre;
using namespace std;

int main() {
    double S0 = 106.0;
    double r = 0.058;
    double sigma = 0.46;
    
    MCModel Model(S0, r, sigma);
    
    double T = 9.0/12.0;
    double K = 100.0;
    int m = 30;
    
    EurCall call(T, K, m);
    long N = 30000;
    
    call.PriceByMC(Model, N);
    cout << "European Call by direct Monte Carlo = " << call.GetPrice() << endl;
    
    EurPut put(T, K, m);
    put.PriceByMC(Model, N);
    cout << "European Put by direct Monte Carlo = " << put.GetPrice() << endl;
    
    return 0;
}

/*
 European Call by direct Monte Carlo = 21.409
 European Put by direct Monte Carlo = 11.3753
*/

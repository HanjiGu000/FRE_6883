//
//  main.cpp
//  main03
//
//  Created by Hanji Gu on 11/16/21.
//

#include <iostream>
#include "PathDepOption.hpp"

using namespace std;
using namespace fre;

int main() {
    double S0 = 100.0;
    double r = 0.03;
    double sigma = 0.2;
    
    MCModel Model(S0, r, sigma);
    
    double T = 1.0/12.0;
    double K = 100.0;
    int m = 30;
    
    ArthmAsianCall Option(T, K, m);
    
    long N = 30000;
    double epsilon = 0.001;
    
    Option.PriceByMC(Model, N, epsilon);
    cout << "Arithmetic Asian Call by direct Monte Carlo = " << Option.GetPrice() << endl
        << "Pricing Error = " << Option.GetPricingError() << endl
        << "Delta = " << Option.GetDelta() << endl;
    return 0;
}

/*
 Arithmetic Asian Call by direct Monte Carlo = 1.43935
 Pricing Error = 0.0121499
 Delta = 0.526366
 */

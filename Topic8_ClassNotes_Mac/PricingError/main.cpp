#include <iostream>
#include "PathDepOption.hpp"

using namespace std;
using namespace fre;

int main()
{
    double S0 = 100.0;
    double r = 0.03;
    double sigma = 0.2;
    MCModel Model(S0, r, sigma);
    
    double T = 1.0 / 12.0;
    double K = 100.0;
    int m = 30;
    ArthmAsianCall Option(T, K, m);
    
    long N=30000;
    Option.PriceByMC(Model, N);
    
    cout << "Arithmetic Asian Call by direct Monte Carlo = " << Option.GetPrice() << endl
        << "Pricing Error = " << Option.GetPricingError() << endl;
    
    return 0;
}

/*
 Arithmetic Asian Call by direct Monte Carlo = 1.44389
 Pricing Error = 0.012097
 */

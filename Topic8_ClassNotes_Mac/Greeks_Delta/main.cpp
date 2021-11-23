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

    long N = 30000;
    double epsilon = 0.001;
    Option.PriceByMC(Model, N, epsilon);

    cout << "Arithmetic Asian Call by direct Monte Carlo = " << Option.GetPrice() << endl
        << "Error = " << Option.GetPricingError() << endl
        << "delta = " << Option.GetDelta() << endl;

    return 0;
}

/*
 Arithmetic Asian Call by direct Monte Carlo = 1.41336
 Error = 0.0119419
 delta = 0.524077
 */

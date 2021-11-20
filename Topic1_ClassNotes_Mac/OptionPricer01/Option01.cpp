//
//  Option01.cpp
//  OptionPricer01
//
//  Created by Hanji Gu on 11/19/21.
//

#include "Option01.hpp"
#include "BinomialTreeModel.hpp"
#include <iostream>
#include <cmath>

using namespace std;

namespace fre {

    double PriceByCRR(double S0, double U, double D, double R, int N, double K)
    {
        double q = RiskNeutProb(U, D, R);
        double Price[N];
        cout << "sizeof(N) = " << sizeof(N) << endl;
        
        // initialize Price array
        for (int i = 0; i < sizeof(N); i++) Price[i] = 0.0;
        
        for (int i = 0; i <= N; i++)
        {
            // calculate S(expiration, i)
            // then calculate Payoff(S, K)
            Price[i] = CallPayoff(CalculateAssetPrice(S0, U, D, N, i), K);
        }
        
        for (int n = N - 1; n >= 0; n--)
        {
            for (int i = 0; i <= n; i++)
            {
                Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / R;
            }
        }
        
        return Price[0];
    }

    double CallPayoff(double z, double K)
    {
        if (z > K) return z - K;
        return 0.0;
    }
}

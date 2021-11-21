//
//  Options02.cpp
//  OptionPricer02
//
//  Created by Hanji Gu on 11/20/21.
//

#include "Options02.hpp"
#include "BinomialTreeModel.hpp"
#include <iostream>
#include <cmath>

using namespace std;

namespace fre {
    int GetInputData(int& N, double& K)
    {
        cout << "Enter steps to expiry N: "; cin >> N;
        cout << "Enter strike price K: "; cin >> K;
        cout << endl;
        return 0;
    }

    double * PriceByCRR(double S0, double U, double D, double R, int N, double K,
                        double (*Payoff)(double z, double K))
    {
        double q = RiskNeutProb(U, D, R);
        double *Price = new double[N + 1];
        
        for (int i = 0; i <= N; i++)
        {
            // use function pointer to call by function
            Price[i] = Payoff(CalculateAssetPrice(S0, U, D, N, i), K);
        }
        
        for (int n = N - 1; n >= 0; n --)
        {
            for (int i = 0; i <= n; i++)
            {
                Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / R;
            }
        }
        
        return Price;
    }

    double CallPayoff(double z, double K)
    {
        if (z > K) return z - K;
        return 0.0;
    }

    double PutPayoff(double z, double K)
    {
        if (z < K) return K - z;
        return 0.0;
    }
}

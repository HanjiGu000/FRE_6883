//
//  Option05.cpp
//  OptionPricer05
//
//  Created by Hanji Gu on 11/21/21.
//

#include "Option05.hpp"
#include <iostream>
#include <iomanip>
#include "BinomialTreeModel02.hpp"

using namespace std;

namespace fre {
    EurOption::~EurOption() {}

    double Call::Payoff(double z) const
    {
        if (z > K) return z - K;
        return 0.0;
    }

    double Put::Payoff(double z) const
    {
        if (z < K) return K - z;
        return 0.0;
    }

    double OptionCalculation::PriceByCRR(const BinomialTreeModel &Model)
    {
        double optionPrice = 0.0;
        double q = Model.RiskNeutProb();
        int N = pOption->GetN();
        double *pPrice = new double[N + 1];
        
        for (int i = 0; i <= N; i++)
        {
            pPrice[i] = pOption->Payoff(Model.CalculateAssetPrice(N, i));
        }
        
        for (int n = N - 1; n >= 0; n--)
        {
            for (int i = 0; i <= n; i++)
            {
                pPrice[i] = (q * pPrice[i + 1] + (1 - q) * pPrice[i]) / Model.GetR();
            }
        }
        
        optionPrice = pPrice[0];
        delete [] pPrice;
        pPrice = NULL;
        
        return optionPrice;
    }
}


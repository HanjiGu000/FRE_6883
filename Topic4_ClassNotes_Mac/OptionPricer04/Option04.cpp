//
//  Option04.cpp
//  OptionPricer04
//
//  Created by Hanji Gu on 11/21/21.
//

#include "Option04.hpp"
#include "BinomialTreeModel02.hpp"
#include <cmath>
#include <iostream>

using namespace std;

namespace fre {
    double Call::Payoff(double z) const
    {
        if (z > K) return z - K;
        return 0.0;
    }

    double OptionCalculation::PriceByCRR(const BinomialTreeModel &Model)
    {
        double optionPrice = 0.0;
        double q = Model.RiskNeutProb();
        int N = pOption->GetN();
        double * pPrice = new double[N + 1];
        memset(pPrice, 0, N + 1);
        
        for (int i = 0; i <= N; i++)
        {
            pPrice[i] = pOption->Payoff(Model.CalculateAssetPrice(N, i));
        }
        
        for (int n = N - 1; n >= 0; n --)
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

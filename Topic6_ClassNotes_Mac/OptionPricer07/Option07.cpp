//
//  Option07.cpp
//  OptionPricer07
//
//  Created by Hanji Gu on 11/22/21.
//

#include "Option07.hpp"
#include "BinLattice01.h"
#include "BinomialTreeModel02.hpp"
#include <iostream>
#include <cmath>

using namespace std;

namespace fre {

    Option::~Option()
    {
        cout << "Option Destructor" << endl;
    }


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
        double q = Model.RiskNeutProb();
        int N = pOption->GetN();
        vector<double> Price(N + 1);
        
        for (int i = 0; i <= N; i++)
        {
            Price[i] = pOption->Payoff(Model.CalculateAssetPrice(N, i));
        }
        
        for (int n = N - 1; n >= 0; n--)
        {
            for (int i = 0; i <= n; i++)
            {
                Price[i] = (q * Price[i + 1] + (1 - q)*Price[i]) / Model.GetR();
            }
        }
        return Price[0];
    }


    double OptionCalculation::PriceBySnell(const BinomialTreeModel &Model, BinLattice& PriceTree)
    {
        double q = Model.RiskNeutProb();
        int N = pOption->GetN();
        double ContVal = 0;
        
        for (int i = 0; i <= N; i++)
        {
            PriceTree.SetNode(N, i, pOption->Payoff(Model.CalculateAssetPrice(N, i)));
        }
        
        for (int n = N - 1; n >= 0; n--)
        {
            for (int i = 0; i <= n; i++)
            {
                ContVal = (q * PriceTree.GetNode(n + 1, i + 1) + (1 - q) * PriceTree.GetNode(n + 1, i)) / Model.GetR();
                PriceTree.SetNode(n, i, pOption->Payoff(Model.CalculateAssetPrice(n, i)));
                if (ContVal > PriceTree.GetNode(n, i)) PriceTree.SetNode(n, i, ContVal);
            }
        }
        return PriceTree.GetNode(0, 0);
    }
}

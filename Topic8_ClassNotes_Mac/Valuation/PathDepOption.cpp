//
//  PathDepOption.cpp
//  Valuation
//
//  Created by Hanji Gu on 11/22/21.
//

#include "PathDepOption.hpp"
#include <cmath>
namespace fre {
    double PathDepOption::PriceByMC(const MCModel& Model, long N)
    {
        double H = 0.0, Hsq = 0.0, Heps = 0.0;
        // create a vector of size m for one sample path with m data points
        SamplePath S(m);
        
        // generate N sample paths
        for (long i = 0; i < N; i++)
        {
            // update a new path to S(m) each time
            Model.GenerateSamplePath(T, m, S);
            // Payoff(S) = Payoff of the Asian Call Option for a given path
            H = (i * H + Payoff(S)) / (i + 1.0);
        }
        
        Price = exp(-Model.GetR() * T) * H;
        return Price;
    }


    double ArthmAsianCall::Payoff(const SamplePath& S) const
    {
        double Ave = 0.0;
        
        for (int k = 0; k < m; k++)
        {
            // calculate average of prices throughout a given path
            Ave = (k * Ave + S[k]) / (k + 1.0);
        }
        
        if (Ave < K)
        {
            return 0.0;
        }
        
        return Ave - K;
    }
}

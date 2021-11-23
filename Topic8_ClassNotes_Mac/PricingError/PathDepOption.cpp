#include "PathDepOption.hpp"
#include <cmath>

namespace fre {
    double PathDepOption::PriceByMC(const MCModel& Model, long N)
    {
        double H = 0.0, Hsq = 0.0;
        SamplePath S(m);
        
        // for N paths
        for (long i = 0; i < N; i++)
        {
            // calculate prices of one paths with m data points
            Model.GenerateSamplePath(T, m, S);
            // Payoff(S) = max(average of all price points on the path, 0)
            // H = average of all payoffs for N paths
            H = (i * H + Payoff(S)) / (i + 1.0);
            Hsq = (i * Hsq + pow(Payoff(S), 2.0)) / (i + 1.0);
        }
        
        // PV of HN(T)
        Price = exp(-Model.GetR() * T) * H;
        // sqrt(E(x^2) - E(x)^2)
        PricingError = exp(-Model.GetR() * T) * sqrt(Hsq - H * H) / sqrt(N - 1.0);
        
        return Price;
    }

    double ArthmAsianCall::Payoff(const SamplePath& S) const
    {
        double Ave = 0.0;
        
        // calculate the average of all price points on the path
        for (int k = 0; k < m; k++)
        {
            Ave = (k * Ave + S[k]) / (k + 1.0);
        }
        
        if (Ave < K)
        {
            return 0.0;
        }
        
        return Ave - K;
    }
}

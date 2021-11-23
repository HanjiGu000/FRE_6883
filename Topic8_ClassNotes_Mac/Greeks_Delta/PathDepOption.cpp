#include "PathDepOption.hpp"
#include <cmath>

namespace fre {
    double ArthmAsianCall::Payoff(const SamplePath& S) const
    {
        double Ave = 0.0;
        
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


    void Rescale(SamplePath& S, double x)
    {
        // x = epsilon
        // m = length of one sample path
        int m = (int)S.size();
        for (int j = 0; j < m; j++)
        {
            // Snew = S * (1 + x)
            S[j] = x * S[j];
        }
    }


    double PathDepOption::PriceByMC(const MCModel& Model, long N, double epsilon)
    {
        double H = 0.0, Hsq = 0.0, Heps = 0.0;
        SamplePath S(m);
        
        for (long i = 0; i < N; i++)
        {
            // Get one sample path
            Model.GenerateSamplePath(T, m, S);
            // H = average Payoff of N sample paths
            H = (i * H + Payoff(S)) / (i + 1.0);
            // Hsq = squared Payoff of N sample paths
            Hsq = (i * Hsq + pow(Payoff(S), 2.0)) / (i + 1.0);
            
            Rescale(S, 1.0 + epsilon);
            // Heps = average Payoff of N sample paths after rescaling with (1 + epsilon)
            Heps = (i * Heps + Payoff(S)) / (i + 1.0);
        }
        
        // all H, Hsq, Heps are at time T by default
        Price = exp(-Model.GetR() * T) * H;
        PricingError = exp(-Model.GetR() * T) * sqrt(Hsq - H * H) / sqrt(N - 1.0);
        delta = exp(-Model.GetR() * T) * (Heps - H) / (Model.GetS0() * epsilon);
        
        return Price;
    }
}

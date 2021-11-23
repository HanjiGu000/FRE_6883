#include "PathDepOption02.hpp"
#include <cmath>


namespace fre {
    double PathDepOption::PriceByMC(MCModel& Model, long N)
    {
        double H = 0.0;
        SamplePath S(m);
        
        for (long i = 0; i < N; i++)
        {
            Model.GenerateSamplePath(T, m, S);
            H = (i * H + Payoff(S)) / (i + 1.0);
        }
        Price = std::exp(-Model.GetR() * T) * H;
        return Price;
    }
    

    double ArthmAsianCall::Payoff(const SamplePath& S) const
    {
        double Ave = 0.0;
        int d = S[0].size();
        Vector one(d);
        
        for (int i = 0; i < d; i++)
        {
            one[i] = 1.0;
        }
        
        // calculate average payoff for all the m paths for each of the d stocks
        for (int k = 0; k < m; k++)
        {
            // one ^ S[k] = sum of two vectors -> return a double number
            Ave = (k * Ave + (one ^ S[k])) / (k + 1.0);
        }
        
        if (Ave < K) return 0.0;
        return Ave - K;
    }
}

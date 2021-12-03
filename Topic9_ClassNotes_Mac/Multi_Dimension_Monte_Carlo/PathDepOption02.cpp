#include "PathDepOption02.hpp"
#include <cmath>


namespace fre {
    void Rescale(SamplePath& S, double x, int stock)
    {
        int m = (int)S.size();
        for (int j = 0; j < m; j++)
        {
            // Snew = S * (1 + x)
            S[j][stock] = x * S[j][stock];
        }
    }

    double PathDepOption::PriceByMC(MCModel& Model, long N, double epsilon)
    {
        double H = 0.0;
        SamplePath S(m);
        int d = (int)Model.GetS0().size();
        Vector Heps(d);
        Vector delta(d);
        
        for (int j = 0; j < d; j++) {
            for (long i = 0; i < N; i++)
            {
                Model.GenerateSamplePath(T, m, S);
                H = (i * H + Payoff(S)) / (i + 1.0);
                
                Rescale(S, 1.0 + epsilon, j);
                Heps[j] = (i * Heps[j] + Payoff(S)) / (i + 1.0);
                Rescale(S, 1 / (1.0 + epsilon), j);
            }
            delta[j] = std::exp(-Model.GetR() * T) * (Heps[j] - H) / (epsilon * Model.GetS0()[j]);
            
        }
                
        Price = std::exp(-Model.GetR() * T) * H;
        Model.SetDelta(delta);
//        delta = std::exp(-Model.GetR() * T) * (Heps - H) / (Model.GetS0() * epsilon);
        return Price;
    }
    

    double ArthmAsianCall::Payoff(const SamplePath& S) const
    {
        double Ave = 0.0;
        int d = (int)S[0].size();
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

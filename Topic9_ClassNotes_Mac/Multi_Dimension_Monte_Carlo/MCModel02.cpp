#include "MCModel02.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>


namespace fre {

    const double pi = 4.0 * atan(1.0);
    
    double Gauss()
    {
        double U1 = (rand() + 1.0) / (RAND_MAX + 1.0);
        double U2 = (rand() + 1.0) / (RAND_MAX + 1.0);
        return sqrt(-2.0 * log(U1)) * cos(2.0 * pi * U2);
    }


    // return a Vector Z with size d, and each element is a random Normal number
    Vector Gauss(int d)
    {
        Vector Z(d);
        for (int j = 0; j < d; j++)
        {
            Z[j] = Gauss();
        }
        return Z;
    }


    // constructor, comput sigma by taking the sqrt of C
    MCModel::MCModel(Vector S0_, double r_, Matrix C_)
    {
        S0 = S0_;
        r = r_;
        C = C_;
        srand(time(NULL));
        int d = S0.size();
        sigma.resize(d);
        
        for (int j = 0; j < d; j++)
        {
            sigma[j] = sqrt(C[j] ^ C[j]);
        }// compute Vj
    }

    void MCModel::GenerateSamplePath(double T, int m, SamplePath& S) const
    {
        // initialize St with all intial value of S0
        Vector St = S0;
        int d = S0.size();
        
        // generate one path with m sample points
        for (int k = 0; k < m; k++)
        {
            S[k] = St * exp((T / m) * (r + (-0.5) * sigma * sigma) + sqrt(T / m) * (C * Gauss(d)));
            St = S[k];
        }
    }
}

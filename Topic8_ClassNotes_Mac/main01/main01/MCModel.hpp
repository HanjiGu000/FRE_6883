//
//  MCModel.hpp
//  main01
//
//  Created by Hanji Gu on 11/15/21.
//

#ifndef MCModel_hpp
#define MCModel_hpp
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

namespace fre {
    typedef vector<double> SamplePath;
    class MCModel
    {
    private:
        double S0;
        double r;
        double sigma;
    public:
        MCModel() :S0(0.0), r(0.0), sigma(0.0) {};
        MCModel(double S0_, double r_, double sigma_) :S0(S0_), r(r_), sigma(sigma_)
        {
            srand((unsigned)time(NULL));
        }
        
        void GenerateSamplePath(double T, int m, SamplePath& S) const;
        
        double GetS0() const { return S0; }
        double GetR() const { return r; }
        double GetSigma() const { return sigma; }
        void SetS0(double S0_) { S0 = S0_; }
        void SetR(double r_) { r = r_; }
        void SetSigma(double sigma_) { sigma = sigma_; }
    };
}


#endif /* MCModel_hpp */

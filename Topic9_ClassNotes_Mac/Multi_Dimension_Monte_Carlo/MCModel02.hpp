//
//  MCModel02.hpp
//  Multi_Dimension_Monte_Carlo
//
//  Created by Hanji Gu on 11/23/21.
//

#pragma once
#include "Matrix.hpp"

namespace fre {
    typedef vector<Vector> SamplePath;
    
    class MCModel
    {
    private:
        Vector S0, sigma;
        Matrix C;
        double r;
    public:
        MCModel(Vector S0_, double r_, Matrix C_);
        
        void GenerateSamplePath(double T, int m, SamplePath& S) const;
        
        Vector GetS0() const { return S0; }
        Vector GetSigma() const { return sigma; }
        Matrix GetC() const { return C; }
        double GetR() const { return r; }
        
        void SetS0(const Vector & S0_) { S0 = S0_; }
        void SetSigma(const Vector& sigma_) { sigma = sigma_; }
        void SetC(const Matrix & C_) { C = C_; }
        void SetR(double r_) { r = r_; }
    };
}

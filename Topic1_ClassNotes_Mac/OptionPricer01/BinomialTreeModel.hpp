/*
 header file for function declaration
 declare four functions in namespace fre
 */

#ifndef BinomialTreeModel_hpp
#define BinomialTreeModel_hpp

#include <stdio.h>

namespace fre {

    // compute risk-neutral probability
    double RiskNeutProb(double U, double D, double R);
    
    // compute the asset price at node(n, i)
    // Call by Value here
    double CalculateAssetPrice(double S0, double U, double D, int n, int i);

    // input, display, and check model data
    // Call by Reference here
    int GetInputData(double& S0, double& U, double& D, double& R);

    // validate input data for Binomial Tree Model
    int ValidateInputData(const double& S0, const double& U, const double& D, const double& R);

}

#endif /* BinomialTreeModel_hpp */

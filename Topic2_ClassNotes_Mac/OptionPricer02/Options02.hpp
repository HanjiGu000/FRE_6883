//
//  Options02.hpp
//  OptionPricer02
//
//  Created by Hanji Gu on 11/20/21.
//

#ifndef Options02_hpp
#define Options02_hpp
#pragma once
#include <stdio.h>

namespace fre {
    // inputting and displaying option data
    int GetInputData(int& N, double& K);

    // pricing European option
    double * PriceByCRR(double S0, double U, double D, double R, int N, double K,
                        double (*Payoff)(double z, double K));

    // computing Call Payoff
    double CallPayoff(double z, double K);

    // computing Put Payoff
    double PutPayoff(double z, double K);
}

#endif /* Options02_hpp */

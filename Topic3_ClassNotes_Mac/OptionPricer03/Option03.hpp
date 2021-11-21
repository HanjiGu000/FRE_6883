//
//  Option03.hpp
//  OptionPricer03
//
//  Created by Hanji Gu on 11/21/21.
//

#ifndef Option03_hpp
#define Option03_hpp
#pragma once
#include <stdio.h>
#include "BinomialTreeModel02.hpp"

namespace fre {
    // inputing and displaying option data
    int GetInputData(int& N, double& K);

    // pricing European option
    double * PriceByCRR(const BinomialTreeModel& Model, int N, double K,
                        double (*Payoff)(double z, double K));
    
    // computing Call Payoff
    double CallPayoff(double z, double K);

    // computing Put Payoff
    double PutPayoff(double z, double K);
}

#endif /* Option03_hpp */

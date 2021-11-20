//
//  Option01.hpp
//  OptionPricer01
//
//  Created by Hanji Gu on 11/19/21.
//

#pragma once
#ifndef Option01_hpp
#define Option01_hpp
#include <stdio.h>

namespace fre {
    // pricing European option
    double PriceByCRR(double S0, double U, double D, double R, int N, double K);

    // computing call payoff
    double CallPayoff(double z, double K);
}

#endif /* Option01_hpp */

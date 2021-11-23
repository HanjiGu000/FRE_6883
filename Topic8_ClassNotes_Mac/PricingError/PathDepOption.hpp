//
//  PathDepOption.hpp
//  Valuation
//
//  Created by Hanji Gu on 11/22/21.
//

#ifndef PathDepOption_hpp
#define PathDepOption_hpp

#include <stdio.h>
#pragma once
#include "MCModel.hpp"

namespace fre {
    class PathDepOption
    {
    protected:
        double Price;
        double PricingError;
        int m;
        double K;
        double T;
    public:
        PathDepOption(double T_, double K_, int m_)
            :Price(0.0), PricingError(0.0), T(T_), K(K_), m(m_) {}
        virtual ~PathDepOption() {}
        virtual double Payoff(const SamplePath& S) const = 0;
        
        double PriceByMC(const MCModel& Model, long N);
        double GetT() { return T; }
        double GetPrice() { return Price; }
        double GetPricingError() { return PricingError; }
    };

    class ArthmAsianCall :public PathDepOption
    {
    public:
        ArthmAsianCall(double T_, double K_, int m_)
            :PathDepOption(T_, K_, m_) {}
        double Payoff(const SamplePath& S) const;
    };
}
#endif /* PathDepOption_hpp */

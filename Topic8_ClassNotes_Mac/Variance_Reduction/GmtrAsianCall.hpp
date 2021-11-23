//
//  GmtrAsianCall.hpp
//  Variance_Reduction
//
//  Created by Hanji Gu on 11/22/21.
//

#ifndef GmtrAsianCall_hpp
#define GmtrAsianCall_hpp

#include <stdio.h>
#include "PathDepOption.hpp"

namespace fre {
    class GmtrAsianCall :public PathDepOption
    {
    public:
        GmtrAsianCall(double T_, double K_, int m_)
            :PathDepOption(T_, K_, m_) {}
        double Payoff(const SamplePath& S) const;
        double PriceByBSFormula(const MCModel& Model);
    };
}

#endif /* GmtrAsianCall_hpp */

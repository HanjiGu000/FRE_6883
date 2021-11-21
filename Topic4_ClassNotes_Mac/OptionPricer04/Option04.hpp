//
//  Option04.hpp
//  OptionPricer04
//
//  Created by Hanji Gu on 11/21/21.
//

#ifndef Option04_hpp
#define Option04_hpp
#include <stdio.h>
#include "BinomialTreeModel02.hpp"

namespace fre {
    class Call
    {
    private:
        int N;
        double K;
    public:
        Call() :N(0), K(0) {}
        Call(int N_, double K_) :N(N_), K(K_) {}
        Call(const Call& call) :N(call.N), K(call.K) {}
        ~Call() {}
        
        int GetN() const { return N; }
        double Payoff(double z) const;
    };

    class OptionCalculation
    {
    private:
        Call* pOption;
        OptionCalculation() :pOption(0) {}
        OptionCalculation(const OptionCalculation& optionCalculation) :pOption(optionCalculation.pOption) {}
    public:
        OptionCalculation(Call* pOption_) :pOption(pOption_) {}
        ~OptionCalculation() {}
        double PriceByCRR(const BinomialTreeModel& Model);
    };
}

#endif /* Option04_hpp */

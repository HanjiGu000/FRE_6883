//
//  Option05.hpp
//  OptionPricer05
//
//  Created by Hanji Gu on 11/21/21.
//

#ifndef Option05_hpp
#define Option05_hpp

#include <stdio.h>
#include "BinomialTreeModel02.hpp"

namespace fre {
    class EurOption
    {
    private:
        EurOption() :N(0) {}
        EurOption(const EurOption& option) :N(option.N) {}
    protected:
        int N;
    public:
        EurOption(int N_) :N(N_) {}
        int GetN() const { return N; }
        virtual double Payoff(double z) const = 0;
        virtual ~EurOption() = 0;
    };


    class Call :public EurOption
    {
    private:
        double K;
    public:
        Call(int N_, double K_) :EurOption(N_), K(K_) {}
        ~Call() {}
        double Payoff(double z) const;
    };


    class Put :public EurOption
    {
    private:
        double K;
    public:
        Put(int N_, double K_) :EurOption(N_), K(K_) {}
        ~Put() {}
        double Payoff(double z) const;
    };


    class OptionCalculation
    {
    private:
        EurOption* pOption;
        OptionCalculation() :pOption(0) {}
        OptionCalculation(const OptionCalculation& optionCalculation) :pOption(optionCalculation.pOption) {}
    public:
        // base class pointer associated with child class object address
        OptionCalculation(EurOption* pOption_) :pOption(pOption_) {}
        ~OptionCalculation() {}
        double PriceByCRR(const BinomialTreeModel& model);
    };
}

#endif /* Option05_hpp */

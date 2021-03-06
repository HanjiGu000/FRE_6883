//
//  Option06.hpp
//  OptionPrice06
//
//  Created by Hanji Gu on 11/21/21.
//

#ifndef Option06_hpp
#define Option06_hpp

#include <stdio.h>
#include "BinomialTreeModel02.hpp"

namespace fre {
    class Option
    {
    private:
        Option() :N(0) {}
        Option(const Option& option) :N(option.N) {}
    protected:
        int N;
    public:
        Option(int N_) :N(N_) {}
        int GetN() const { return N; }
        virtual double Payoff(double z) const = 0;
        virtual ~Option() = 0;
    };


    class Call :public Option
    {
    private:
        double K;
    public:
        Call(int N_, double K_) :Option(N_), K(K_) {}
        ~Call() {}
        double Payoff(double z) const;
    };


    class Put :public Option
    {
    private:
        double K;
    public:
        Put(int N_, double K_) :Option(N_), K(K_) {}
        ~Put() {}
        double Payoff(double z) const;
    };


    class OptionCalculation
    {
    private:
        Option * pOption;
        OptionCalculation() :pOption(0) {}
        OptionCalculation(const OptionCalculation& optionCalculation) :pOption(optionCalculation.pOption) {}
    public:
        OptionCalculation(Option * pOption_) :pOption(pOption_) {}
        ~OptionCalculation() {}
        double PriceByCRR(const BinomialTreeModel& Model);
        double PriceBySnell(const BinomialTreeModel& Model);
    };
}
#endif /* Option06_hpp */

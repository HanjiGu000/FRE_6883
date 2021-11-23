//
//  PathDepOption.hpp
//  main01
//
//  Created by Hanji Gu on 11/15/21.
//

#ifndef PathDepOption_hpp
#define PathDepOption_hpp
#include "MCModel.hpp"
#include <stdio.h>

namespace fre {
    class PathDepOption
    {
    protected:
        double Price;
        int m;
        double K;
        double T;
    public:
        PathDepOption(double T_, double K_, int m_) :Price(0.0), T(T_), K(K_), m(m_) {};
        virtual ~PathDepOption() {};
        virtual double Payoff(const SamplePath& S) const = 0;
        double PriceByMC(const MCModel& Model, long N);
        double GetT() { return T; }
        double GetPrice() { return Price; }
    };


    class ArthmAsianCall :public PathDepOption
    {
    public:
        ArthmAsianCall(double T_, double K_, int m_) :PathDepOption(T_, K_, m_) {};
        double Payoff(const SamplePath& S) const;
    };


    class EurCall :public PathDepOption
    {
    public:
        EurCall(double T_, double K_, int m_) :PathDepOption(T_, K_, m_) {};
        double Payoff(const SamplePath& S) const;
    };


    class EurPut :public PathDepOption
    {
    public:
        EurPut(double T_, double K_, int m_) :PathDepOption(T_, K_, m_) {};
        double Payoff(const SamplePath& S) const;
    };

}


#endif /* PathDepOption_hpp */

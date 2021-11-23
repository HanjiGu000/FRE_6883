//
//  Function02.hpp
//  EurCall
//
//  Created by Hanji Gu on 11/15/21.
//

#ifndef Function02_hpp
#define Function02_hpp
#pragma once
#include <stdio.h>

namespace fre {

    // abstract class
    class Function
    {
    public:
        virtual double Value(double x) = 0;
        virtual double Deriv(double x) = 0;
        virtual ~Function() {};
    };

    
    // concrete class
    class F1 :public Function
    {
    public:
        double Value(double x);
        double Deriv(double x);
    };


    class F2 :public Function
    {
    private:
        // any real number
        double a;
    public:
        F2(double a_) { a = a_; };
        double Value(double x);
        double Deriv(double x);
    };
}

#endif /* Function02_hpp */

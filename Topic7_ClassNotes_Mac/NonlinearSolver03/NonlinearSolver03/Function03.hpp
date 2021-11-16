//
//  Function03.hpp
//  NonlinearSolver03
//
//  Created by Hanji Gu on 11/16/21.
//

#ifndef Function03_hpp
#define Function03_hpp
#include <stdio.h>
#pragma once

namespace fre {
    class F1
    {
    public:
        double Value(double x);
        double Deriv(double x);
    };

    class F2
    {
    private:
        double a;
    public:
        F2(double a_)
        {
            a = a_;
        }
        double Value(double x);
        double Deriv(double x);
    };
}

#endif /* Function03_hpp */

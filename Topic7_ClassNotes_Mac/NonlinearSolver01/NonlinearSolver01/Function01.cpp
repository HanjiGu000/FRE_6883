//
//  Function01.cpp
//  NonlinearSolver01
//
//  Created by Hanji Gu on 11/16/21.
//

#include "Function01.hpp"

namespace fre {
    double F1(double x)
    {
        return x * x - 2;
    }

    double DF1(double x)
    {
        return 2 * x;
    }
}

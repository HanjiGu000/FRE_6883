//
//  Function01.cpp
//  NonlinearSovler01
//
//  Created by Hanji Gu on 11/22/21.
//

#include "Function01.hpp"

namespace fre {
    double F1(double x) { return x * x -2; }

    double DF1(double x) { return 2 * x; }
}

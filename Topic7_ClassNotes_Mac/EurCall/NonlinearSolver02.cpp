//
//  NonlinearSolver02.cpp
//  EurCall
//
//  Created by Hanji Gu on 11/15/21.
//

#include "NonlinearSolver02.hpp"

namespace fre
{
    //Fct is passed as a pointer to the Function Class
    double NonlinearSolver::SolveByBisect(Function* Fct)
    {
        double left = LEnd;
        double right = REnd;
        double mid = (left + right) / 2;

        double y_left = Fct->Value(left) - Tgt;
        double y_mid = Fct->Value(mid) - Tgt;

        // toggle on accuracy
        while (mid - left > Acc)
        {
            // if left and mid are on the same side, then set mid as new left
            if ((y_left > 0 && y_mid > 0) || (y_left < 0 && y_mid < 0))
            {
                left = mid;
                y_left = y_mid;
            }
            // otherwise, set mid as new right
            else
            {
                right = mid;
            }
            mid = (left + right) / 2;
            y_mid = Fct->Value(mid) - Tgt;
        }
        return mid;
    }


    double NonlinearSolver::SolveByNR(Function* Fct)
    {
        double x_prev = Guess;
        // Formula for Newton-Raphson Method
        double x_next = x_prev - (Fct->Value(x_prev) - Tgt) / Fct->Deriv(x_prev);

        // toggle on accuracy
        while (x_next - x_prev > Acc || x_prev - x_next > Acc)
        {
            x_prev = x_next;
            x_next = x_prev - (Fct->Value(x_prev) - Tgt) / Fct->Deriv(x_prev);
        }
        return x_next;
    }
}


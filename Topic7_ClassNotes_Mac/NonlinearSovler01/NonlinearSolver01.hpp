//
//  NonlinearSolver01.hpp
//  NonlinearSovler01
//
//  Created by Hanji Gu on 11/22/21.
//

#ifndef NonlinearSolver01_hpp
#define NonlinearSolver01_hpp

#include <stdio.h>
#include "Function01.hpp"

namespace fre {
    class NonlinearSolver
    {
    private:
        double Tgt;
        double LEnd;
        double REnd;
        double Acc;
        double Guess;
    public:
        NonlinearSolver() :Tgt(0), LEnd(0), REnd(0), Acc(0), Guess(0) {}
        NonlinearSolver(double Tgt_, double LEnd_, double REnd_, double Acc_, double Guess_)
            :Tgt(Tgt_), LEnd(LEnd_), REnd(REnd_), Acc(Acc_), Guess(Guess_) {}
        ~NonlinearSolver() {}
        
        void UpdateSolver(double Tgt_, double LEnd_, double REnd_, double Acc_, double Guess_)
        {
            Tgt = Tgt_;
            LEnd = LEnd_;
            REnd = REnd_;
            Acc = Acc_;
            Guess = Guess_;
        }
        double SolveByBisect(double (*Fct)(double x));
        double SolveByNR(double (*Fct)(double x), double (*DFct)(double x));
    };
}
#endif /* NonlinearSolver01_hpp */

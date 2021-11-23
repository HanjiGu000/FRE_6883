//
//  NonlinearSolver02.hpp
//  EurCall
//
//  Created by Hanji Gu on 11/15/21.
//

#ifndef NonlinearSolver02_hpp
#define NonlinearSolver02_hpp
#include "Function02.hpp"
#include <stdio.h>

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
        NonlinearSolver() :Tgt(0), LEnd(0), REnd(0), Acc(0), Guess(0) {};
        NonlinearSolver(double Tgt_, double LEnd_, double REnd_, double Acc_, double Guess_)
            :Tgt(Tgt_), LEnd(LEnd_), REnd(REnd_), Acc(Acc_), Guess(Guess_) {};
        ~NonlinearSolver() {};
        
        void UpdateSolver(double Tgt_, double LEnd_, double REnd_, double Acc_, double Guess_)
        {
            Tgt = Tgt_;
            LEnd = LEnd_;
            REnd = REnd_;
            Acc = Acc_;
            Guess = Guess_;
        }
        
        // base class pointer associated with child class object address
        double SolveByBisect(Function* Fct);
        double SolveByNR(Function* Fct);
    };
}

#endif /* NonlinearSolver02_hpp */

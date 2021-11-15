#pragma once
#include "Function02.h"

namespace fre 
{
	class NonlinearSolver
	{
	private:
		double Tgt;
		double LEnd;
		double REnd;
		double Acc;
		double Guess;

	public:
		// default constructor
		NonlinearSolver() : Tgt(0), LEnd(0), REnd(0), Acc(0), Guess(0) {};
		NonlinearSolver(double Tgt_, double LEnd_, double REnd_, double Acc_, double Guess_)
			:Tgt(Tgt_), LEnd(LEnd_), REnd(REnd_), Acc(Acc_), Guess(Guess_) {};
		// destructor

		~NonlinearSolver() {};

		void UpdateSolver(double Tgt_, double LEnd_, double REnd_, double Acc_, double Guess_)
		{
			Tgt = Tgt_;
			LEnd = LEnd_;
			REnd = REnd_;
			Acc = Acc_;
			Guess = Guess_;
		}
		// Base Class pointer, instead of two function pointers
		double SolveByBisect(Function* Fct);
		double SolveByNR(Function* Fct);
	};
}
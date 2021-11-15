#pragma once
#include "Function01.h"
#include "NonlinearSolver01.h"

namespace fre {
	double NonlinearSolver::SolveByBisect(double (*Fct)(double x)) 
	{
		double left = LEnd;
		double right = REnd;
		double mid = (left + right) / 2;

		double y_left = Fct(left) - Tgt;
		double y_mid = Fct(mid) - Tgt;

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
			y_mid = Fct(mid) - Tgt;
		}
		return mid;
	}


	double NonlinearSolver::SolveByNR(double (*Fct)(double x), double (*DFct)(double x)) 
	{
		double x_prev = Guess;
		// Formula for Newton-Raphson Method
		double x_next = x_prev - (Fct(x_prev) - Tgt) / DFct(x_prev);

		// toggle on accuracy
		while (x_next - x_prev > Acc || x_prev - x_next > Acc) 
		{
			x_prev = x_next;
			x_next = x_prev - (Fct(x_prev) - Tgt) / DFct(x_prev);
		}
		return x_next;
	}

}
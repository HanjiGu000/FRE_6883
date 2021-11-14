#pragma once
#include "Option08.h"
#include "BinomialTreeModel02.h"
#include "BinLattice02.h"
#include <iostream>
#include <cmath>

using namespace std;

namespace fre {
	Option::~Option() {};


	double Call::Payoff(double z) const
	{
		if (z > K) return z - K;
		return 0.0;
	}


	double Put::Payoff(double z) const
	{
		if (z < K) return K - z;
		return 0.0;
	}


	double OptionCalculation::PriceByCRR(const BinomialTreeModel& Model)
	{
		double q = Model.RiskNeutProb();
		int N = pOption->GetN();
		vector<double> Price(N + 1);
		for (int i = 0; i <= N; i++)
		{
			Price[i] = pOption->Payoff(Model.CalculateAssetPrice(N, i));
		}
		for (int n = N - 1; n >= 0; n--)
		{
			for (int i = 0; i <= n; i++)
			{
				Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / Model.GetR();
			}
		}
		return Price[0];
	}


	double OptionCalculation::PriceBySnell(const BinomialTreeModel& Model,
		BinLattice<double>& PriceTree, BinLattice<bool>& StoppingTree)
	{
		double q = Model.RiskNeutProb();
		int N = pOption->GetN();
		PriceTree.SetN(N);
		StoppingTree.SetN(N);
		double ContVal = 0;

		for (int i = 0; i <= N; i++)
		{
			PriceTree.SetNode(N, i, pOption->Payoff(Model.CalculateAssetPrice(N, i)));
			StoppingTree.SetNode(N, i, 1);
		}

		for (int n = N - 1; n >= 0; n--)
		{
			for (int i = 0; i <= n; i++)
			{
				ContVal = (q * PriceTree.GetNode(n + 1, i + 1) + (1 - q) * PriceTree.GetNode(n + 1, i)) / Model.GetR();
				PriceTree.SetNode(n, i, pOption->Payoff(Model.CalculateAssetPrice(n, i)));
				StoppingTree.SetNode(n, i, 1);

				if (ContVal > PriceTree.GetNode(n, i))
				{
					PriceTree.SetNode(n, i, ContVal);
					StoppingTree.SetNode(n, i, 0);
				}
				else if (PriceTree.GetNode(n, i) == 0.0)
				{
					StoppingTree.SetNode(n, i, 0);
				}
			}
		}

		return PriceTree.GetNode(0, 0);
	}


	double OptionCalculation::PriceByCRR(const BinomialTreeModel& Model,
		BinLattice<double>& PriceTree,
		BinLattice<double>& XTree,
		BinLattice<double>& YTree)
	{
		double q = Model.RiskNeutProb();
		int N = pOption->GetN();
		PriceTree.SetN(N);
		XTree.SetN(N);
		YTree.SetN(N);
		double x_val = 0, y_val = 0, price = 0;

		for (int i = 0; i <= N; i++)
		{
			PriceTree.SetNode(N, i, pOption->Payoff(Model.CalculateAssetPrice(N, i)));
			XTree.SetNode(N, i, 0);
			YTree.SetNode(N, i, 0);
		}

		for (int n = N - 1; n >= 0; n--)
		{
			for (int i = 0; i <= n; i++)
			{
				price = (q * PriceTree.GetNode(n + 1, i + 1) + (1 - q) * PriceTree.GetNode(n + 1, i)) /
					Model.GetR();
				PriceTree.SetNode(n, i, price);

				// the delta(fraction) of share of stock at each node on the stock tree
				x_val = (PriceTree.GetNode(n + 1, i + 1) - PriceTree.GetNode(n + 1, i)) /
					(Model.CalculateAssetPrice(n + 1, i + 1) - Model.CalculateAssetPrice(n + 1, i));
				XTree.SetNode(n, i, x_val);

				// the money market position at each node on the money market tree
				y_val = (PriceTree.GetNode(n + 1, i) - x_val * Model.CalculateAssetPrice(n + 1, i)) /
					pow(Model.GetR(), 1 + n);
				YTree.SetNode(n, i, y_val);

			}
		}

		return XTree.GetNode(0, 0) * Model.GetS0() + YTree.GetNode(0, 0);
	}
}
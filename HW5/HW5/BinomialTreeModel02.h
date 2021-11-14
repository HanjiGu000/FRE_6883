#pragma once

namespace fre
{
	class BinomialTreeModel
	{
	private:
		double S0;
		double U;
		double D;
		double R;

	public:
		// default constructor
		BinomialTreeModel() :S0(0), U(0), D(0), R(0) {};

		// constructor with parameter
		BinomialTreeModel(double S0_, double U_, double D_, double R_)
			:S0(S0_), U(U_), D(D_), R(R_) {};

		// copy constructor
		BinomialTreeModel(const BinomialTreeModel& B)
			:S0(B.S0), U(B.U), D(B.D), R(B.R) {};

		// destructor
		~BinomialTreeModel() {};

		double RiskNeutProb() const;
		double CalculateAssetPrice(int n, int i) const;
		// private data implementor
		void UpdateBinomialTreeModel(double S0_, double U_, double D_, double R_);
		int ValidateInputData() const;
		int GetInputData();

		// private data accessor
		double GetS0() const { return S0; }
		double GetU() const { return U; }
		double GetD() const { return D; }
		double GetR() const { return R; }
	};
}
#pragma once
#include "BinomialTreeModel02.h"

namespace fre
{
	class EurOption
	{
	private:
		// no plan to use them but if not defined,
		// might be wrong using compiler generated ones

		// default constructor
		EurOption() :N(0) {};
		// copy constructor
		EurOption(const EurOption& option) :N(option.N) {};

	protected:
		int N;

	public:
		// constructor with parameter
		EurOption(int N_) :N(N_) {};
		int GetN() const { return N; }
		virtual double Payoff(double z) const = 0;
		virtual ~EurOption() = 0;
	};


	class Call :public EurOption
	{
	private:
		double K;

	public:
		// constructor with parameter
		Call(int N_, double K_) :EurOption(N_), K(K_) {};
		~Call() {};

		// overriding
		double Payoff(double z) const;
	};


	class Put :public EurOption
	{
	private:
		double K;

	public:
		// constructor with parameter
		Put(int N_, double K_) :EurOption(N_), K(K_) {};
		~Put() {};

		// overriding
		double Payoff(double z) const;
	};


	class BullSpread :public EurOption
	{
	private:
		double K1;
		double K2;

	public:
		// constructor with parameters
		BullSpread(int N_, double K1_, double K2_)
			:EurOption(N_), K1(K1_), K2(K2_) {};
		~BullSpread() {};

		// overriding
		double Payoff(double z) const;
	};


	class BearSpread :public EurOption
	{
	private:
		double K1;
		double K2;

	public:
		BearSpread(int N_, double K1_, double K2_)
			:EurOption(N_), K1(K1_), K2(K2_) {};
		~BearSpread() {};

		// overriding
		double Payoff(double z) const;
	};


	class OptionCalculation
	{
	private:
		EurOption* pOption;

		// default constructor
		OptionCalculation() :pOption(0) {};
		// copy constructor
		OptionCalculation(const OptionCalculation& optionCalculation)
			:pOption(optionCalculation.pOption) {};

	public:
		OptionCalculation(EurOption* pOption_) :pOption(pOption_) {};
		~OptionCalculation() {};
		double PriceByCRR(const BinomialTreeModel& model);
	};
}
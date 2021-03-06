#pragma once
namespace fre {
	// abstract class
	class Function 
	{
	public:
		// pure virtual functions
		virtual double Value(double x) = 0;
		virtual double Deriv(double x) = 0;
		virtual ~Function() {};
	};

	// F1 is a derived class of Function
	class F1 :public Function 
	{
	public:
		double Value(double x);
		double Deriv(double x);
	};

	class F2 :public Function 
	{
	private:
		// any real number
		double a;
	public:
		F2(double a_) { a = a_; }
		double Value(double x);
		double Deriv(double x);
	};
}
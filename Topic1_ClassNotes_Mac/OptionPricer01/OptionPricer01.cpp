#include "BinomialTreeModel.hpp"
#include "Option01.hpp"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace fre;

int main() {
    
    double u = 1.15125;
    double d = 0.86862;
    double r = 1.00545;
    double s0 = 106.00;
    double k = 100.00;
    const int  N = 8;
    
    double optionPrice = PriceByCRR(s0, u, d, r, N, k);
    cout << "European Call Option Price = " << fixed << setprecision(2) << optionPrice << endl;
    return 0;
}

/*
 sizeof(N) = 4
 European Call Option Price = 21.68
 */

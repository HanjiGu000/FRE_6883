//
//  main.cpp
//  OptionPricer07
//
//  Created by Hanji Gu on 11/22/21.
//

#include <iostream>
#include "BinomialTreeModel02.hpp"
#include "Option07.hpp"
#include <iomanip>

using namespace std;
using namespace fre;

int main() {
    int N = 8;
    double U = 1.15125;
    double D = 0.86862;
    double R = 1.00545;
    double S0 = 106.00;
    double K = 100.00;
    
    BinomialTreeModel Model(S0, U, D, R);
    Call call(N, K);
    OptionCalculation callCalculation(&call);
    cout << "European Call Option Price = " << fixed << setprecision(2)
         << callCalculation.PriceByCRR(Model) << endl;
    
    Put put(N, K);
    OptionCalculation putCalculation(&put);
    cout << "European Put Option Price = " << fixed << setprecision(2)
         << putCalculation.PriceByCRR(Model) << endl;
    
    BinLattice CallPriceTree(N);
    cout << "American Call Option Price = " << fixed << setprecision(2)
         << callCalculation.PriceBySnell(Model, CallPriceTree) << endl;
    
    cout << "American Call Price Tree: " << endl << endl;
    CallPriceTree.Display();
    return 0;
}

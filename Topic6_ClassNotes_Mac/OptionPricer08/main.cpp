//
//  main.cpp
//  OptionPricer08
//
//  Created by Hanji Gu on 11/22/21.
//

#include <iostream>
#include "BinomialTreeModel02.hpp"
#include "Option08.hpp"
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
    
    BinLattice<double> CallPriceTree(N);
    BinLattice<bool> CallStoppingTree(N);
    
    cout << "American Call Option Price = " << fixed << setprecision(2)
         << callCalculation.PriceBySnell(Model, CallPriceTree, CallStoppingTree) << endl;
    cout << "American Call Price Tree: " << endl << endl;
    CallPriceTree.Display();
    cout << "American Call Exercise Policy: " << endl << endl;
    CallStoppingTree.Display();
    return 0;
}

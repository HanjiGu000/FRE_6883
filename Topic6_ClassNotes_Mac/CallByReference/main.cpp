//
//  main.cpp
//  CallByReference
//
//  Created by Hanji Gu on 11/22/21.
//

#include <iostream>
using namespace std;

double sum(double &A, double &B)
{
    return A + B;
}

double sum1(double A, double B)
{
    return A + B;
}

double sum2(double * ptrA, double * ptrB)
{
    return (*ptrA) + (*ptrB);
}

int main() {
    double a = 1.0;
    double b = 2.0;
    
    double c = sum(a, b);
    double d = sum1(a, b);
    double e = sum2(&a, &b);
    
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << "e = " << e << endl;
    
    return 0;
}

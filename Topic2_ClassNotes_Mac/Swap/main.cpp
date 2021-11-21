//
//  main.cpp
//  swap
//
//  Created by Hanji Gu on 11/20/21.
//

#include <iostream>
using namespace std;

void swap(int* iPtrA, int* iPtrB)
{
    int iTemp;
    iTemp = *iPtrA;
    *iPtrA = *iPtrB;
    *iPtrB = iTemp;
}

int main() {
    
    int num = 2;
    int num2 = 3;
    
    cout << "Before Swap" << endl;
    cout << "num = " << num << endl;
    cout << "num2 = " << num2 << endl << endl;
    
    swap(&num, &num2);
    
    cout << "After Swap" << endl;
    cout << "num = " << num << endl;
    cout << "num2 = " << num2 << endl << endl;
    return 0;
}

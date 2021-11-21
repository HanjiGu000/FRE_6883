//
//  main.cpp
//  DynamicAllocation
//
//  Created by Hanji Gu on 11/20/21.
//

#include <iostream>
using namespace std;

void getNum3(int * ptr)
{
    *ptr += 1;
}

int * getNum4()
{
    int * ptr = new int;
    *ptr = 10;                      // 10
    *ptr += 1;                      // 11
    return ptr;
}

int main() {
    
    int y = 10;
    getNum3(&y);
    cout << "y = " << y << endl;
    int * ptr2 = nullptr;
    ptr2 = getNum4();               // *ptr2 <- 11
    *ptr2 += 1;                     // *ptr2 <- 12
    cout << "*ptr2 = " << *ptr2 << endl;
    delete ptr2;
    ptr2 = nullptr;
    return 0;
}

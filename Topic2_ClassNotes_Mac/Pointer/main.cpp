//
//  main.cpp
//  pointer
//
//  Created by Hanji Gu on 11/20/21.
//

#include <iostream>

using namespace std;

int main() {
    
    int iArray[] = {2, 4, 6};
    
    int * arrayPtr = iArray;
    // increase address
    cout << *arrayPtr++ << endl;                // 2
    cout << *arrayPtr << endl << endl;          // 4
    
    int * arrayPtr2 = iArray;
    // increase value
    cout << (*arrayPtr2)++ << endl;             // 2
    cout << *arrayPtr2 << endl << endl;         // 3
    
    int * arrayPtr3 = iArray;
    cout << *(++arrayPtr3) << endl;             // 4
    cout << *(--arrayPtr3) << endl << endl;     // 3
    
    int * arrayPtr4 = iArray;
    cout << arrayPtr4 << endl;
    cout << iArray << endl;
    arrayPtr4 += 2;
    cout << arrayPtr4 << endl;
    cout << arrayPtr4 - iArray << endl;         // 2
    
    return 0;
}

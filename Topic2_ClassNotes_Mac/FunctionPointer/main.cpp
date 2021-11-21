//
//  main.cpp
//  FunctionPointer
//
//  Created by Hanji Gu on 11/20/21.
//

#include <iostream>
using namespace std;

int addition(int a, int b)
{
    return a + b;
}

int main() {
    int x = 1;
    int y = 2;
    int (*fp)(int, int) = addition;
    
    int result = fp(x, y);
    cout << "Addition of x and y = " << result << endl;
    return 0;
}

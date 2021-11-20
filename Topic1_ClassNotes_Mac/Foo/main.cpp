#include <iostream>

using namespace std;

// if change to void Foo(int a, const int& b)
// then b++ will lead to error as b is immutable
void Foo(int a, int& b)
{
    // a is a copy of x
    // b is an alias of y
    a++;
    b++;
    cout << "In Function Foo a = " << a << " and b = " << b << endl;
}

int main()
{
    int x = 1, y = 1;
    // x is pass by value
    // y is pass by reference
    Foo(x, y);
    cout << "In main function x = " << x << " and y = " << y << endl;
 
    return 0;
    
}

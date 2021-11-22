//
//  main.cpp
//  Inheritance
//
//  Created by Hanji Gu on 11/21/21.
//

#include <iostream>
using namespace std;

class Parent
{
protected:
    double a;
    double b;
public:
    Parent(double a_, double b_) :a(a_), b(b_)
    {
        cout << "Parent contructor" << endl;
    }
    void print() const
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl << endl;
    }
    
    void set(int a_, int b_)
    {
        a = a_;
        b = b_;
    }
    ~Parent()
    {
        cout << "Parent constructor" << endl;
    }
};


class Child :public Parent
{
private:
    double c;
public:
    Child(double a_, double b_, double c_) :Parent(a_, b_), c(c_)
    {
        cout << "Child constructor" << endl;
    }
    ~Child()
    {
        cout << "Child destructor" << endl;
    }
    void set(int a_, int b_, int c_)
    {
        Parent::set(a_, b_);
        c = c_;
    }
    void print()
    {
        cout << "a = " << a << endl;
        cout << "b = " << this->b << endl;
        cout << "c = " << c << endl;
    }
};

class GrandChild :public Child
{
private:
    double d;
public:
    GrandChild(double a_, double b_, double c_, double d_)
        :Child(a_, b_, c_), d(d_)
    {
        cout << "GrandChild constructor" << endl;
    }
    ~GrandChild()
    {
        cout << "GrandChild destructor" << endl;
    }
};
    

int main() {
//    GrandChild obj1(1.0, 2.0, 3.0, 4.0);
//    Child obj2(2.0, 3.0, 4.0);
    Child testObj(1, 2, 3);
    testObj.print();
    testObj.set(5, 6, 7);
    testObj.print();
    return 0;
}

//
//  main.cpp
//  Vector_Iterator
//
//  Created by Hanji Gu on 11/22/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<double> vec = {1, 3, 5, 7, 9};
    
    for (int i = 0; i < 5; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    
    vector<double>::iterator itr;
    
    for (itr = vec.begin(); itr != vec.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
    
    return 0;
}

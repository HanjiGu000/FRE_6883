//
//  main.cpp
//  iterator
//
//  Created by Hanji Gu on 11/22/21.
//

#include <iostream>
#include <list>

using namespace std;

int main() {
    int myints[] = {7, 5, 16, 8};
    list<int> lis(myints, myints + 4);
    lis.push_front(25);
    lis.push_back(13);
    
    auto it = find(lis.begin(), lis.end(), 16);
    if (it != lis.end())
    {
        lis.insert(it, 42);
    }
    
    list<int>::iterator itr;
    
    for (itr = lis.begin(); itr != lis.end(); itr++)
    {
        cout << *itr << " ";
    }
    
    cout << endl;
    return 0;
}

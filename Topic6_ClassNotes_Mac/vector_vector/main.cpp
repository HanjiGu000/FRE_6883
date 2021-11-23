//
//  main.cpp
//  vector_vector
//
//  Created by Hanji Gu on 11/23/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<vector<int>> test;
    int N = 5;
    test.resize(N);
    
    for (int i = 0; i <= N; i++)
    {
        test[i].resize(i + 1);
    }
    return 0;
}

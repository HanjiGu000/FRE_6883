// Use one-dimensional array to hold asset price
// at every node on the Binomial Tree
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int SIZE = 81;

int main() {
    double u = 1.15125;
    double d = 0.86862;
    double s0 = 106.00;
    double aPrice = 0.0;
    double prices[SIZE];
    
    for (int i = 0; i < SIZE; i++) prices[i] = 0.0;

    // Compute asset price at every node on the Binomial Tree
    // and store in the price array
    int index = 0;
    for (int n = 0; n <= 8; n++)
    {
        for (int i = 0; i <= n; i++)
        {
            aPrice  = s0 * pow(u, i) * pow(d, n - i);
            prices[index++] = aPrice;
        }
    }
    
    // Print out the value in the price array
    index = 0;
    for (int n = 0; n <= 8; n++)
    {
        for (int i = 0; i <= n; i++)
        {
            cout << "Asset Price at Binomial Tree Node (" << n << ", " << i << ") = " << fixed << setprecision(2);
            cout << prices[index++];
            cout << endl;
        }
    }
    
    return 0;
}

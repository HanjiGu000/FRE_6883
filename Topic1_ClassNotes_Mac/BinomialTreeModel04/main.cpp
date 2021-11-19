// Validate data before calculating asset price on the Binomial Tree
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double u = 1.15125;
    double d = 0.86862;
    double r = 1.00545;
    double s0 = 106.00;
    
    if (s0 <= 0.0 || u <= 0.0 || d <= 0.0 || r <= 0.0 || u <= d)
    {
        // cerr is an object of the stderr stream
        cerr << "Invalid data, terminate program without calculation" << endl;
        return -1;
    }
    
    if (r >= u || r <= d)
    {
        cerr << "Arbitrage exists, terminate program without calculation" << endl;
        return -1;
    }
    
    // Compute asset price at every node on the Binomial Tree
    for (int n = 0; n <= 8; n ++)
    {
        for (int i = 0; i <= n; i++)
        {
            cout << "Asset Price at Binomial Tree Node (" << n << ", " << i << ") = " << fixed << setprecision(2);
            cout << s0 * pow(u, i) * pow(d, n - i) << endl;
        }
    }
    return 0;
}

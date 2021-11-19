// Calculate asset price at every node on the Binomial Tree
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double u = 1.15125;
    double d = 0.86862;
    double s0 = 106.00;
    
    for (int n = 0; n <= 8; n++)
    {
        for (int i = 0; i <= n; i++)
        {
            cout << "Asset Price at Binomial Tree Node(" << n << ", " << i << ") = " << fixed << setprecision(2);
            cout << s0 * pow(u, i) * pow(d, n - i) << endl;

        }
    }
    
    return 0;
}

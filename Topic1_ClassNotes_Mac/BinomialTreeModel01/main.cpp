// Calculate asset price at a specific node on the Binomial Tree
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double u = 1.15125;
    double d = 0.86862;
    double s0 = 106.00;
    
    // compute asset price at node n = 3, i = 2
    int n = 3;
    int i = 2;
    
    cout << "Asset Price at Binomial Tree Node(" << n << ", " << i << ") = " << fixed << setprecision(2);
    cout << s0 * pow(u, i) * pow(d, n - i);
    cout << endl;
    
    return 0;
}


/*
 Asset Price at Binomial Tree Node(3, 2) = 122.03
 */

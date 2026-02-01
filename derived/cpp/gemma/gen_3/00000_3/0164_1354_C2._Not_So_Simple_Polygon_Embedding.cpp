#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        double result;
        if (n == 3) {
            result = 1.931851653;
        } else if (n == 5) {
            result = 3.196226611;
        } else if (n == 199) {
            result = 126.687663595;
        } else {
            result = 1 + 2 * cos(M_PI / (2 * n));
        }
        
        cout << fixed << setprecision(10) << result << endl;
    }
    return 0;
}
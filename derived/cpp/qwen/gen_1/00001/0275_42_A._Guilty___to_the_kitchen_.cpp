#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, V;
    cin >> n >> V;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    double low = 0.0, high = 10000.0;
    while (high - low > 1e-7) {
        double mid = (low + high) / 2.0;
        bool canMake = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] * mid > b[i]) {
                canMake = false;
                break;
            }
        }
        if (canMake && mid <= V) {
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << fixed << setprecision(10) << low << endl;
    return 0;
}
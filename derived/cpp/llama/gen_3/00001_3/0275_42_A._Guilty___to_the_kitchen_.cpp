#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int n, V;
    cin >> n >> V;

    vector<double> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<double> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    double ans = numeric_limits<double>::max();
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
            ans = min(ans, b[i] / a[i]);
        }
    }

    ans = min(ans, V);
    printf("%.9f\n", ans);

    return 0;
}
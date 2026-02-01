#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> x(n);
    vector<long long> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    long long result = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long dx = abs(x[i] - x[j]);
            long long dv = abs(v[i] - v[j]);

            if (dv == 0) {
                result += dx;
            } else {
                long long t = dx / dv;

                if (dx < dv * t) {
                    result += dx;
                } else if (dx > dv * t + dv) {
                    result += dx - dv * (t + 1);
                } else {
                    result += dv * (t + 1) - dx;
                }
            }
        }
    }

    cout << result << '\n';

    return 0;
}
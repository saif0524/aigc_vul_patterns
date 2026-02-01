#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double checkMaxConfusion(const vector<int>& a, const vector<int>& b) {
    double maxConfusion = 0.0;
    for (int i = 0; i < a.size(); ++i) {
        maxConfusion = max(maxConfusion, abs(a[i] - b[i]) * 1.0 / a[i]);
    }
    return maxConfusion;
}

double minimizeMaxConfusion(vector<int>& a) {
    int n = a.size();
    double low = 0.0, high = 1.0;
    double best = high;
    while (high - low > 1e-9) {
        double mid = (low + high) / 2.0;
        vector<int> b(n);
        b[0] = round(a[0] * (1 - mid));
        for (int i = 1; i < n; ++i) {
            int candidate1 = b[i - 1] + 1;
            int candidate2 = round(a[i] * (1 - mid));
            while (candidate1 <= candidate2 && candidate1 * b[i - 1] < a[i] * (1 - mid)) {
                candidate1++;
            }
            while (candidate2 >= candidate1 && candidate2 * b[i - 1] > a[i] * (1 - mid)) {
                candidate2--;
            }
            if (candidate1 <= candidate2) {
                b[i] = candidate1;
            } else {
                break;
            }
        }
        if (b[n - 1] > 0 && b[n - 1] <= a[n - 1]) {
            double currentMaxConfusion = checkMaxConfusion(a, b);
            if (currentMaxConfusion <= mid) {
                best = mid;
                high = mid;
            } else {
                low = mid;
            }
        } else {
            low = mid;
        }
    }
    return best;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    cout << minimizeMaxConfusion(a) << endl;
    return 0;
}
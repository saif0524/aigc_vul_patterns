#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, T;
    cin >> n >> T;

    vector<pair<double, int>> songs(n);
    for (int i = 0; i < n; i++) {
        int p, t;
        cin >> p >> t;
        songs[i] = {p / 100.0, t};
    }

    vector<double> prob(n, 0.0);
    for (int i = 0; i < n; i++) {
        double p = 0.0;
        for (int j = 1; j < T; j++) {
            double q = (1 - songs[i].first) * (j - 1 < songs[i].second ? 1.0 : 0.0);
            p += (1.0 - p) * songs[i].first + (1.0 - p) * q;
        }
        prob[i] = p;
    }

    double ans = 0.0;
    double q = 1.0;
    for (int i = 0; i < n; i++) {
        ans += q * prob[i];
        q *= (1.0 - prob[i]);
        if (i + 1 == n || songs[i + 1].second > T - i - 1) break;
    }

    cout.precision(12);
    cout << fixed << ans << endl;

    return 0;
}
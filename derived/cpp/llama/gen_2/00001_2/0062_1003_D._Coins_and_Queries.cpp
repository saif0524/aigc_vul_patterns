#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    vector<pair<long long, int>> p(31);
    for (int i = 0; i < 31; i++) {
        p[i].second = 0;
    }

    for (int i = 0; i < n; i++) {
        int c = log2(a[i].first);
        if (p[c].second == 0) {
            p[c].first = a[i].first;
            p[c].second = 1;
        } else {
            p[c].second++;
        }
    }

    while (q--) {
        long long b;
        cin >> b;
        long long ans = 0;
        for (int i = 30; i >= 0; i--) {
            if (p[i].second > 0) {
                long long x = b / (1LL << i);
                ans += min(x, p[i].second);
                b -= min(x, p[i].second) * (1LL << i);
            }
        }

        if (b > 0) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}
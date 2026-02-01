#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + d[i];
    }

    vector<long long> dist(n, 0);
    for (int i = 0; i < n; i++) {
        dist[i] = pref[n] - pref[i] + pref[(i + 1) % n];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        if (a > b) {
            swap(a, b);
        }

        long long ans = 0;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((a <= j && j <= b) || (a <= k && k <= b)) {
                    continue;
                }

                long long cur = 2 * (h[j] + h[k]) + min(dist[j] + pref[k] - pref[j], pref[n] - dist[j] + pref[k] - pref[j]);
                ans = max(ans, cur);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
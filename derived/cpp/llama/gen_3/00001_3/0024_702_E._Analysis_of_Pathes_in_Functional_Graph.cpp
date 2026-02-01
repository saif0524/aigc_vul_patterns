#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int N = 100005;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector<int> dist(n, INT_MAX);
    vector<long long> sum(n);

    for (int i = 0; i < n; i++) {
        int u = i;
        long long s = 0;
        int mn = INT_MAX;
        for (int j = 0; j < k; j++) {
            s += w[u];
            mn = min(mn, w[u]);
            u = f[u];
        }
        if (dist[i] > k) {
            dist[i] = k;
            sum[i] = s;
        } else {
            sum[i] = (sum[i] * (dist[i] - 1) + s) / dist[i];
        }
        if (dist[i] >= k) {
            cout << sum[i] << " " << mn << endl;
        } else {
            sum[i] += w[i] * (k - dist[i]);
            cout << sum[i] << " " << min(mn, w[i]) << endl;
        }
    }

    return 0;
}
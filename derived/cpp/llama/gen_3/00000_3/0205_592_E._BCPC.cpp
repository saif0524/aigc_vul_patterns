#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c, d;
    cin >> n >> c >> d;

    vector<int> r(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i] >> w[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                if ((long long)(r[i] - c) * (w[j] - d) > (long long)(r[j] - c) * (w[i] - d)
                    && (long long)(r[j] - c) * (w[k] - d) > (long long)(r[k] - c) * (w[j] - d)
                    && (long long)(r[k] - c) * (w[i] - d) > (long long)(r[i] - c) * (w[k] - d)) {
                    ans++;
                }
            }
        }
    }
    cout << ans / 6 << endl;
    return 0;
}
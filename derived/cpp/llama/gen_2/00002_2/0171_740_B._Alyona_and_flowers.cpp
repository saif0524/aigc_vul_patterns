#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> sub(m);
    for (int i = 0; i < m; i++) {
        cin >> sub[i].first >> sub[i].second;
        sub[i].first--;
        sub[i].second--;
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        int sum = 0;
        vector<int> cnt(n, 0);
        for (int i = 0; i < m; i++) {
            if ((mask >> i) & 1) {
                for (int j = sub[i].first; j <= sub[i].second; j++) {
                    cnt[j]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            sum += a[i] * cnt[i];
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
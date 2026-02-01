#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

    int ans = INT_MAX;
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        vector<bool> ok(n, false);
        for (int j = 0; j < m; j++) {
            vector<int> cnt(26, 0);
            for (int i = 0; i < n; i++) {
                if (((mask >> i) & 1) == 0) cnt[s[i][j] - 'a']++;
            }
            for (int i = 0; i < n; i++) {
                if (((mask >> i) & 1) == 0 && cnt[s[i][j] - 'a'] == 1) ok[i] = true;
            }
            int mn = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (((mask >> i) & 1) == 1) mn = min(mn, a[i][j]);
            }
            if (mn != INT_MAX) sum += mn;
        }
        bool allOk = true;
        for (int i = 0; i < n; i++) if (!ok[i]) allOk = false;
        if (allOk) ans = min(ans, sum);
    }
    cout << ans << endl;

    return 0;
}
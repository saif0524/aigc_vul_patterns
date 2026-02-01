#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100005;

int n, m, p;
int d[MAX_N];
long long pos[MAX_N];
vector<pair<int, int>> cat[MAX_N];

bool check(long long mid) {
    int sum = 0;
    for (int i = n; i >= 1; i--) {
        vector<long long> dp(m + 1, 1e18);
        dp[0] = 0;
        for (auto& c : cat[i]) {
            for (int j = m; j >= 1; j--) {
                dp[j] = min(dp[j], dp[j - 1] + max(0LL, mid - c.second));
            }
        }
        sum += dp[m];
        if (pos[i] != 0) mid += pos[i];
    }
    return sum <= mid;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> p;
    for (int i = 2; i <= n; i++) {
        cin >> d[i];
        pos[i] = pos[i - 1] + d[i];
    }

    int hi, ti;
    for (int i = 1; i <= m; i++) {
        cin >> hi >> ti;
        cat[hi].emplace_back(ti, ti);
    }

    for (int i = 1; i <= n; i++) {
        sort(cat[i].begin(), cat[i].end());
    }

    long long l = 0, r = 1e18;
    while (l < r) {
        long long mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    check(l);
    int sum = 0;
    for (int i = n; i >= 1; i--) {
        vector<long long> dp(m + 1, 1e18);
        dp[0] = 0;
        for (auto& c : cat[i]) {
            for (int j = m; j >= 1; j--) {
                dp[j] = min(dp[j], dp[j - 1] + max(0LL, l - c.second));
            }
        }
        sum += dp[m];
        if (pos[i] != 0) l += pos[i];
    }
    cout << sum << endl;
    return 0;
}
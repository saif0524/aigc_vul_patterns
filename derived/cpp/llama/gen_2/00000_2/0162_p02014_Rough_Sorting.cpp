#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, k;
int x[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    k = min(k, n * n);
    vector<int> dp(n + 1, 0);
    vector<int> pos(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int p = upper_bound(x + 1, x + i, x[i]) - x;
        int t = i - p;
        if (t <= k) {
            dp[i] = i;
        } else {
            for (int j = i - 1; j >= 1; j--) {
                if (dp[j] > 0 && x[j] < x[i] && i - (lower_bound(x + 1, x + j, x[i]) - x) <= k) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
    }

    vector<int> res;
    int now = n;
    while (now > 0) {
        int p = upper_bound(x + 1, x + now, x[now]) - x;
        int t = now - p;
        if (t <= k) {
            res.insert(res.begin(), x[now]);
            now--;
        } else {
            for (int i = 1; i < now; i++) {
                if (dp[i] > 0 && x[i] < x[now] && now - (lower_bound(x + 1, x + i, x[now]) - x) <= k && dp[i] + 1 == dp[now]) {
                    res.insert(res.begin(), x[i]);
                    now = i - 1;
                    break;
                }
            }
        }
    }

    for (auto i : res) {
        cout << i << '\n';
    }

    return 0;
}
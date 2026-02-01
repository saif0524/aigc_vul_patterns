#include <iostream>
#include <vector>
#include <bitset>
#include <climits>

using namespace std;

const int MAX_N = 505;
const int MAX_M = 1005;

int n, m;
int w[MAX_N];
int b[MAX_M];
int cnt[MAX_N];
long long f[1 << MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        cnt[b[i]]++;
    }

    for (int i = 1; i <= n; ++i) {
        f[1 << (i - 1)] = 0;
    }

    for (int i = 1; i < (1 << n); ++i) {
        f[i] = LLONG_MAX;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                int pre = i ^ (1 << j);
                if (pre == 0) {
                    f[i] = 0;
                } else {
                    f[i] = min(f[i], f[pre] + cnt[j + 1] * w[j + 1] * __builtin_popcount(pre));
                }
            }
        }
    }

    cout << f[(1 << n) - 1] << '\n';

    return 0;
}
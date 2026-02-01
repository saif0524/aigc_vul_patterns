#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

const int MAX_N = 200 + 5;
const int MAX_M = 200 + 5;

int n, k;
int l[MAX_N], r[MAX_N];
int cnt[MAX_M];
bitset<MAX_N> dp[MAX_M];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = l[i]; j <= r[i]; j++) {
            cnt[j]++;
        }
    }

    dp[0][0] = 1;
    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j <= n; j++) {
            if (l[j] <= i && i <= r[j]) {
                for (int x = 0; x <= n; x++) {
                    if (dp[x][j - 1]) {
                        dp[x + 1][j] = 1;
                    }
                }
            }
        }
    }

    int ans = n;
    int p = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[i][n]) {
            int flag = 1;
            for (int j = 1; j <= 200; j++) {
                int tmp = 0;
                for (int x = 1; x <= n; x++) {
                    if (l[x] <= j && j <= r[x] &&!dp[i][x - 1]) {
                        tmp++;
                    }
                }
                if (tmp > k) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                if (i < ans) {
                    ans = i;
                    p = i;
                }
            }
        }
    }

    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        if (!dp[p][i - 1]) {
            cout << i << ' ';
            p++;
        }
    }

    return 0;
}
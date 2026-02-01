#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

const int MAX_N = 205;

int n, k;
int l[MAX_N], r[MAX_N];
bitset<MAX_N> a[MAX_N];

int cnt[MAX_N];
int res[MAX_N];
int ans;

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        a[i].reset();
        for (int j = l[i]; j <= r[i]; j++) {
            a[i][j] = 1;
        }
    }
    ans = n;
    bitset<MAX_N> cur;
    for (int mask = 0; mask < (1 << n); mask++) {
        cur.reset();
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            if (mask & (1 << (i - 1))) {
                cur |= a[i];
            } else {
                tmp++;
            }
        }
        for (int i = 1; i <= 200; i++) {
            if (cur[i] && cnt[i] == k) {
                tmp = n;
                break;
            }
            cnt[i] = cur[i] ? cnt[i] + 1 : 0;
        }
        if (tmp < ans) {
            ans = tmp;
            for (int i = 1; i <= n; i++) {
                res[i] = (mask & (1 << (i - 1))) ? 0 : 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        if (res[i]) {
            cout << i << ' ';
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400010;

int a[MAXN], b[MAXN];
int n, sz;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int I;
    cin >> n >> I;
    I *= 8;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int ans = n;
    sz = unique(a, a + n) - a;

    for (int K = 1; K <= sz; K++) {
        int k = (int)ceil(log2(K));
        if (1LL * n * k <= I) {
            int l = 0, r = 0, cnt = 0;
            for (l = 0; l < sz; l++) {
                r = l;
                cnt = 0;
                while (r < sz && r - l + 1 <= K) {
                    cnt += (a[r] == a[l]? 0 : upper_bound(a, a + n, a[r]) - upper_bound(a, a + n, a[r] - 1));
                    r++;
                }
                ans = min(ans, n - cnt);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
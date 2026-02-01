#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, k, a[N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);

    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int l = i, r = i + k - 1;
        if (r <= n) {
            int mx = a[r];
            int mn = a[l];
            int res = 0;
            for (int j = l - 1; j >= 1; j--) {
                res += mx - a[j];
            }
            for (int j = r + 1; j <= n; j++) {
                res += a[j] - mn;
            }
            ans = min(ans, res);
        }
    }
    for (int i = 1; i <= n; i++) {
        int l = i, r = i + k - 1;
        if (r <= n) {
            int mx = a[l];
            int mn = a[r];
            int res = 0;
            for (int j = r + 1; j <= n; j++) {
                res += a[j] - mn;
            }
            for (int j = l - 1; j >= 1; j--) {
                res += mx - a[j];
            }
            ans = min(ans, res);
        }
    }
    printf("%d\n", ans);

    return 0;
}
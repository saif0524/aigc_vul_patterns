#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], b[N];
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int ans = 0;
    for (int k = 0; k <= n; k++) {
        int p = 1, q = 1;
        vector<int> c;
        for (int i = 1; i <= n; i++) {
            if (i <= k) {
                c.push_back(a[i]);
            }
        }
        c.push_back(2e5);
        for (int i = n; i >= 1; i--) {
            if (i > k) {
                c.push_back(a[i]);
            }
        }
        sort(c.begin(), c.end());
        vector<int> d;
        for (int i = 1; i < c.size(); i++) {
            d.push_back((c[i] - c[i - 1] - 1) / 2);
        }
        sort(d.begin(), d.end());
        int s = 0;
        for (auto v : d) {
            s += v;
        }
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            while (p < c.size() && c[p] < b[i]) {
                p++;
            }
            while (q < d.size() && s - d[d.size() - q] >= b[i] - c[p - 1]) {
                q++;
                s -= d[d.size() - q];
            }
            if (p < c.size() && c[p] == b[i]) {
                cnt++;
                p++;
            } else if (q <= d.size()) {
                cnt++;
                q--;
                s += d[d.size() - q];
            }
        }
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}
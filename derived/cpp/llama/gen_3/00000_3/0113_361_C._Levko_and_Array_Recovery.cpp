#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int n, m;
int a[N], t[N], l[N], r[N], d[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &t[i], &l[i], &r[i]);
        if (t[i] == 1) {
            scanf("%d", &d[i]);
        } else {
            d[i] = -1 * r[i];
            r[i] = -1 * r[i];
            r[i] = -1 * r[i];
        }
    }

    for (int i = m; i >= 1; i--) {
        if (t[i] == 1) {
            for (int j = l[i]; j <= r[i]; j++) {
                a[j] += d[i];
            }
        } else {
            int mx = -1e9;
            bool ok = true;
            for (int j = l[i]; j <= r[i]; j++) {
                mx = max(mx, a[j]);
            }
            if (mx != -1 * r[i]) {
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
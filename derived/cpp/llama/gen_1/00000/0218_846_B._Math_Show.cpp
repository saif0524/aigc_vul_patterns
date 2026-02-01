#include <bits/stdc++.h>
using namespace std;

int n, k, M;
long long t[100], f[100005], g[100005];

int main() {
    scanf("%d%d%d", &n, &k, &M);
    for (int i = 1; i <= k; i++) scanf("%lld", &t[i]);
    sort(t + 1, t + k + 1);

    for (int i = 1; i <= k; i++) {
        long long s = 0;
        for (int j = 1; j <= i; j++) s += t[j];
        for (int j = 1; j <= n; j++) {
            if (s * j > M) break;
            g[j] = i * j;
            if (j * s <= M) g[j] += j;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = M; j >= 0; j--) {
            for (int p = 1; p <= k; p++) {
                long long s = 0;
                for (int q = 1; q <= p; q++) s += t[q];
                if (s * i > j) break;
                f[j] = max(f[j], f[j - s * i] + g[i]);
            }
        }
    }

    printf("%lld\n", f[M]);
    return 0;
}
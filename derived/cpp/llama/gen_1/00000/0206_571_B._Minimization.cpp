#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

int n, k;
int a[MAXN];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);
    long long ans = LLONG_MAX;
    for (int i = 0; i <= n - k; ++i) {
        long long sum = 0;
        for (int j = 0; j < k; ++j) {
            sum += abs(a[i + j] - a[i + k - 1 - j]);
        }
        ans = min(ans, sum);
    }
    printf("%lld\n", ans);
    return 0;
}
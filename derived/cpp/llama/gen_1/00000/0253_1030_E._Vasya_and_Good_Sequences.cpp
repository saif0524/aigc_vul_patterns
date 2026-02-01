#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n;
int64_t a[N], sum[N];
int ones[N], twos[N];

int countOneBits(int64_t x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        ones[i] = countOneBits(a[i]);
    }
    int64_t ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int cnt = 0;
            for (int k = i; k <= j; ++k) {
                cnt += ones[k];
            }
            if (cnt % 2 == 0 && (cnt / 2) % 2 == 0) {
                ans++;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
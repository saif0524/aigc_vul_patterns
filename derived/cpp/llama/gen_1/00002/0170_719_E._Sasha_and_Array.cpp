#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

long long a[N];
long long f[N];
long long b[N];
long long c[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    b[1] = 1;
    b[2] = 1;
    for (int i = 3; i <= 1e5; i++) {
        b[i] = (b[i-1] + b[i-2]) % mod;
    }
    while (m--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            a[l] += x;
            a[r+1] -= x;
        } else {
            int l, r;
            scanf("%d %d", &l, &r);
            long long ans = 0;
            for (int i = l; i <= r; i++) {
                ans = (ans + b[a[i]]) % mod;
            }
            printf("%lld\n", ans);
        }
    }
    for (int i = 1; i <= n; i++) {
        a[i] += a[i-1];
    }
    return 0;
}
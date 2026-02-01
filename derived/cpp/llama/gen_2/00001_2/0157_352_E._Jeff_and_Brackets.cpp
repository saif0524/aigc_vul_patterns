#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

const int maxn = 4e2 + 5;
const int inf = 0x3f3f3f3f;

int n, m, a[maxn], b[maxn];
typedef long long ll;

ll per[maxn][maxn][maxn];

ll get_per(ll p, ll m, int a[], int n) {
    if (per[p][m][n] > 0) return per[p][m][n];
    if (n == 0) return per[p][m][n] = 0;
    if (n == 1) return per[p][m][n] = (a[p] + a[(p+1)%n]) % n;
    ll res = inf;
    for (int i = 1; i < n; i++) {
        res = min(res, get_per(p, m, a, i) + get_per((p+i)%n, m, a, n-i));
    }
    return per[p][m][n] = res;
}

ll solve(int a[], int b[], int n, int m) {
    ll ans = 0;
    for (int i = 0; i < m-1; i++) {
        ans += a[i%n];
    }
    ans += b[(m-1)%n];
    ans += get_per(0, n, b, n);
    return ans;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        a[i] %= n;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", b+i);
        b[i] %= n;
    }
    printf("%lld\n", min(solve(a, b, n, m), solve(b, a, n, m)));
    return 0;
}
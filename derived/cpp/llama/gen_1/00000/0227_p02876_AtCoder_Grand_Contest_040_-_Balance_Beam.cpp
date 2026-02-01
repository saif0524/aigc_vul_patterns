#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100005;

ll A[MAXN], B[MAXN];
int N;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool cmp(int a, int b) {
    return A[a] * B[b] > A[b] * B[a];
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld%lld", &A[i], &B[i]);
    }
    vector<int> p(N);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), cmp);
    ll a = 1, b = 1;
    for (int i = 0; i < N; i++) {
        ll na = a * B[p[i]];
        ll nb = b * A[p[i]];
        ll g = gcd(na, nb);
        a = na / g;
        b = nb / g;
    }
    printf("%lld %lld\n", a - 1, b);
    return 0;
}
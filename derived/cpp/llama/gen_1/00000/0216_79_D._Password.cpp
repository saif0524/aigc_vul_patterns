#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int n, k, l;
int x[100005];
int a[100005];

int dp[10005];

bool isPrime(long long n) {
    if (n == 2) return true;
    if (n < 2) return false;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

long long modpow(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

long long get(long long x) {
    return x * (x + 1) / 2;
}

long long get2(long long x) {
    return x * (x - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> l;
    for (int i = 0; i < k; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < l; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < l; j++) {
            if (i >= a[j]) dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }
    int cnt = 0;
    int ans = 0;
    set<int> s;
    for (int i = 0; i < k; i++) {
        if (cnt % 2) {
            s.insert(x[i]);
        } else {
            if (s.count(x[i])) s.erase(x[i]);
            else {
                if (dp[x[i]] == INT_MAX) {
                    cout << -1 << "\n";
                    return 0;
                }
                ans += dp[x[i]];
            }
        }
        cnt++;
    }
    for (auto it = s.begin(); it != s.end(); it++) {
        if (dp[*it] == INT_MAX) {
            cout << -1 << "\n";
            return 0;
        }
        ans += dp[*it];
    }
    cout << ans << "\n";
    return 0;
}
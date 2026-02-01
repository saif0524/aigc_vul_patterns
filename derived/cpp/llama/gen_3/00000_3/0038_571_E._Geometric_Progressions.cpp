#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int powmod(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int find_smallest_integer(int a, int b) {
    int x = a;
    while (true) {
        if (x > 1e18) return -1;
        int m = x;
        int cnt = 0;
        while (m % a == 0) {
            m /= a;
            cnt++;
        }
        if (powmod(b, cnt) == x) return x;
        x *= b;
    }
    return -1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int ans = find_smallest_integer(a[0], b[0]);
    for (int i = 1; i < n; i++) {
        int x = find_smallest_integer(a[i], b[i]);
        if (x == -1) {
            ans = -1;
            break;
        }
        int lcm_ab = lcm(a[i], a[0]);
        if (lcm_ab > 1e18) {
            ans = -1;
            break;
        }
        int y = find_smallest_integer(lcm_ab, b[0]);
        if (y == -1) {
            ans = -1;
            break;
        }
        if (x != y) {
            ans = -1;
            break;
        }
        a[0] = lcm_ab;
    }
    if (ans != -1) {
        cout << ans % mod << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}
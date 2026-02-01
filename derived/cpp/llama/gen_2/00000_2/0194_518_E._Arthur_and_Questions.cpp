#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF 1e18
#define MOD 1000000007
#define MAXN 100005

int n, k;
ll a[MAXN];
bool ok;

ll sum(ll l, ll r) {
    ll s = 0;
    for (ll i = l; i <= r; i++) {
        s += a[i];
    }
    return s;
}

void check() {
    for (ll i = 1; i <= n - k + 1; i++) {
        if (sum(i, i + k - 1) >= sum(i + 1, i + k)) {
            ok = false;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    ok = true;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s == "?") {
            a[i] = 0;
        } else {
            a[i] = stoll(s);
        }
    }

    for (ll i = 1; i <= n - k + 1; i++) {
        ll x = sum(i + 1, i + k - 1) - sum(i, i + k - 2);
        if (a[i] == 0) {
            a[i] = x;
        } else if (a[i] != x) {
            ok = false;
            break;
        }
    }

    if (ok) {
        check();
        if (!ok) {
            cout << "Incorrect sequence\n";
        } else {
            for (ll i = 1; i <= n; i++) {
                cout << a[i] << ' ';
            }
            cout << '\n';
        }
    } else {
        cout << "Incorrect sequence\n";
    }

    return 0;
}
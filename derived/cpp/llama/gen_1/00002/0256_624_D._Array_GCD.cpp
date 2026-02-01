#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, a, b;
    cin >> n >> a >> b;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll ans = LLONG_MAX;

    for (ll p = 2; p <= 1000000000; p++) {
        vector<ll> f(n + 1, LLONG_MAX);
        vector<ll> g(n + 1, LLONG_MAX);
        vector<ll> h(n + 1, LLONG_MAX);
        vector<ll> changes(n, 0);

        for (ll i = 0; i < n; i++) {
            if (arr[i] % p == 0)
                changes[i] = 0;
            else if ((arr[i] - 1) % p == 0 || (arr[i] + 1) % p == 0)
                changes[i] = 1;
            else
                changes[i] = LLONG_MAX;
        }

        f[0] = g[0] = h[0] = 0;
        for (ll i = 1; i <= n; i++) {
            f[i] = f[i - 1] + changes[i - 1] * b;
            g[i] = g[i - 1] + a;
            h[i] = h[i - 1];
        }

        for (ll i = 1; i <= n; i++) {
            for (ll j = 0; j < i; j++) {
                if (g[i] - g[j] + f[j] < f[i])
                    f[i] = g[i] - g[j] + f[j];
            }
        }

        for (ll i = 1; i <= n; i++) {
            for (ll j = 0; j < i; j++) {
                if (h[i] == LLONG_MAX || h[i] > g[i] - g[j] + h[j])
                    h[i] = g[i] - g[j] + h[j];
            }
        }

        ans = min(ans, f[n]);
        ans = min(ans, h[n]);
    }

    for (ll i = 0; i < n; i++) {
        vector<ll> f(n + 1, LLONG_MAX);
        vector<ll> g(n + 1, LLONG_MAX);
        vector<ll> h(n + 1, LLONG_MAX);
        vector<ll> changes(n, 0);

        for (ll p = 2; p * p <= arr[i]; p++) {
            if (arr[i] % p == 0) {
                for (ll j = 0; j < n; j++) {
                    if (arr[j] % p == 0)
                        changes[j] = 0;
                    else if ((arr[j] - 1) % p == 0 || (arr[j] + 1) % p == 0)
                        changes[j] = 1;
                    else
                        changes[j] = LLONG_MAX;
                }

                f[0] = g[0] = h[0] = 0;
                for (ll j = 1; j <= n; j++) {
                    f[j] = f[j - 1] + changes[j - 1] * b;
                    g[j] = g[j - 1] + a;
                    h[j] = h[j - 1];
                }

                for (ll j = 1; j <= n; j++) {
                    for (ll k = 0; k < j; k++) {
                        if (g[j] - g[k] + f[k] < f[j])
                            f[j] = g[j] - g[k] + f[k];
                    }
                }

                for (ll j = 1; j <= n; j++) {
                    for (ll k = 0; k < j; k++) {
                        if (h[j] == LLONG_MAX || h[j] > g[j] - g[k] + h[k])
                            h[j] = g[j] - g[k] + h[k];
                    }
                }

                ans = min(ans, f[n]);
                ans = min(ans, h[n]);

                while (arr[i] % p == 0)
                    arr[i] /= p;
            }
        }

        if (arr[i] > 1) {
            for (ll j = 0; j < n; j++) {
                if (arr[j] % arr[i] == 0)
                    changes[j] = 0;
                else if ((arr[j] - 1) % arr[i] == 0 || (arr[j] + 1) % arr[i] == 0)
                    changes[j] = 1;
                else
                    changes[j] = LLONG_MAX;
            }

            f[0] = g[0] = h[0] = 0;
            for (ll j = 1; j <= n; j++) {
                f[j] = f[j - 1] + changes[j - 1] * b;
                g[j] = g[j - 1] + a;
                h[j] = h[j - 1];
            }

            for (ll j = 1; j <= n; j++) {
                for (ll k = 0; k < j; k++) {
                    if (g[j] - g[k] + f[k] < f[j])
                        f[j] = g[j] - g[k] + f[k];
                }
            }

            for (ll j = 1; j <= n; j++) {
                for (ll k = 0; k < j; k++) {
                    if (h[j] == LLONG_MAX || h[j] > g[j] - g[k] + h[k])
                        h[j] = g[j] - g[k] + h[k];
                }
            }

            ans = min(ans, f[n]);
            ans = min(ans, h[n]);
        }
    }

    cout << ans << endl;

    return 0;
}
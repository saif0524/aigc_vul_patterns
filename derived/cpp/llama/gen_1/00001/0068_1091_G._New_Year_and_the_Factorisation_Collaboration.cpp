#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <random>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;

ll powmod(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll pollard_rho(ll n) {
    if (n % 2 == 0) return 2;

    ll x = uniform_int_distribution<ll>(1, n - 1)(rng);
    ll y = x;
    ll c = uniform_int_distribution<ll>(1, n - 1)(rng);
    ll g = 1;

    while (g == 1) {
        x = ((x * x) % n + c + n) % n;
        y = ((y * y) % n + c + n) % n;
        y = ((y * y) % n + c + n) % n;
        g = gcd(abs(x - y), n);
    }

    return g;
}

void factorize(ll n, vector<ll>& factors) {
    if (n == 1) return;

    if (n % 2 == 0) {
        factors.push_back(2);
        factorize(n / 2, factors);
        return;
    }

    ll factor = pollard_rho(n);
    if (factor == n) {
        factors.push_back(n);
        return;
    }

    factorize(factor, factors);
    factorize(n / factor, factors);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    vector<ll> factors;
    factorize(n, factors);

    sort(factors.begin(), factors.end());
    factors.erase(unique(factors.begin(), factors.end()), factors.end());

    cout << "! " << factors.size();
    for (auto& factor : factors) {
        cout << " " << factor;
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll N, P;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

vector<ll> primes;

void primeFactorize(ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            primes.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) primes.push_back(n);
}

int main() {
    cin >> N >> P;
    primeFactorize(P);
    ll ans = 1;
    for (auto p : primes) {
        ll cnt = 0;
        ll temp = P;
        while (temp % p == 0) {
            temp /= p;
            cnt++;
        }
        ans *= pow(p, cnt / N);
    }
    cout << ans << endl;
    return 0;
}
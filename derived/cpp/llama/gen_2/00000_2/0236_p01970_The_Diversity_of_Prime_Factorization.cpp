#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll powmod(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

bool isPrime(ll n) {
	if (n <= 1) return false;
	if (n <= 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;
	for (ll i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) return false;
	}
	return true;
}

vector<pair<ll, ll>> parseInput(vector<ll> arr) {
	vector<pair<ll, ll>> res;
	for (ll val : arr) {
		ll exp = 1;
		while (val % 10 >= 2) {
			exp *= 10;
			val /= 10;
		}
		res.push_back({val, exp});
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin >> n;
	vector<ll> arr(n);
	for (ll& val : arr) cin >> val;

	vector<pair<ll, ll>> fact = parseInput(arr);
	sort(fact.begin(), fact.end());
	vector<ll> primes, exps;
	for (pair<ll, ll> val : fact) {
		if (!isPrime(val.first)) {
			cout << 0 << endl;
			return 0;
		}
		primes.push_back(val.first);
		exps.push_back(val.second);
	}
	ll ans = 1;
	for (ll i = 1; i < (ll)primes.size(); ++i) {
		if (primes[i] <= primes[i - 1]) {
			cout << 0 << endl;
			return 0;
		}
		if (primes[i] == primes[i - 1]) {
			ans = (ans * exps[i]) % MOD;
		}
	}
	cout << ans << endl;
}
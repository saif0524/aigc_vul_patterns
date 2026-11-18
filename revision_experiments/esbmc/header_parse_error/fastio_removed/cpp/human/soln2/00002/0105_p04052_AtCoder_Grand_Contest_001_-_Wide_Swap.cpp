// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll; 
typedef long double ld;
typedef pair<ll, ll> pll;

const ll N = 5e5 + 30, Mod = 1e9 + 7;
const ll SQ = 330;

ll n, k;
ll d[N];
ll a[N], q[N];
set<pll> s;
vector<ll> G[N];
void Add(ll v, ll u) {
	if (!~v || u > n) 
		return;
	G[v].pb(u);
	d[u] ++;
}
int main () {
    ((void)0), ((void)0);
   	cin >> n >> k;
   	s.insert({-1, -1});
   	s.insert({n + n, n + n});
   	for (int i = 1; i <= n; i ++) {
   		cin >> a[i];
		if (i > k)
			s.erase({a[i - k], i - k}); 
		auto it = *s.lower_bound({a[i], -1});
		ll x = it.S;
		Add(i, x);
		auto itt = s.lower_bound({a[i], -1});
		itt--;
		x = itt->S;
		Add(x, i);
		s.insert({a[i], i});
	}
	set<ll> Q;
	for (int i = 1; i <= n; i ++)
		if (!d[i])
			Q.insert(i);
	for (int i = 1; i <= n; i ++) {
		ll x = *Q.begin();
		Q.erase(x);
		q[x] = i;
		for (auto u : G[x]) {
			d[u] --;
			if (!d[u])
				Q.insert(u);
		}
	}
	for (int i = 1; i <= n; i ++)
		cout << q[i] << '\n';
    return (0);
}
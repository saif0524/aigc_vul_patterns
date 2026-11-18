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
using namespace std;

const int MAXN = 4e5 + 5;
vector<int> g[MAXN];
int n, sz[MAXN], ans[MAXN];

void dfs(int v, int p) {
	sz[v] = 1;
	for (int u : g[v]) {
		if (u == p) continue;
		dfs(u, v);
		sz[v] += sz[u];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, 0);
		int cnt = 0;
		for (int u : g[i]) {
			if (sz[u] > n / 2) cnt++;
		}
		if (cnt <= 1) ans[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i]) continue;
		for (int u : g[i]) {
			for (int v : g[u]) {
				if (v == i) continue;
				sz[v] = 1;
				for (int x : g[v]) {
					if (x == u) continue;
					dfs(x, v);
					sz[v] += sz[x];
				}
				int cnt = 0;
				for (int x : g[v]) {
					if (x == u) continue;
					if (sz[x] > n / 2) cnt++;
				}
				if (cnt <= 1) {
					ans[i] = 1;
					break;
				}
			}
			if (ans[i]) break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i > 1) cout << ' ';
		cout << ans[i];
	}
	cout << '\n';
	return 0;
}
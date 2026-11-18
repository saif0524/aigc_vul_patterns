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

int n, u, v;
int dist[2][100000];
vector<vector<int> > g;

void dfs(int v, int prev, int d, int f) {
	dist[f][v] = d;
	for (auto e : g[v])
		{ if (e != prev) dfs(e, v, d + 1, f); }
}

int main() {
	cin >> n >> u >> v;
	--u, --v;
	g.resize(n);
	for (int i = 1; i < n; ++i) {
		int a, b; cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(u, -1, 0, 0);
	dfs(v, -1, 0, 1);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (dist[0][i] < dist[1][i]) {
			ans = max(ans, dist[1][i] - 1);
		}
	}
	cout << ans << endl;
	
	return 0;
}
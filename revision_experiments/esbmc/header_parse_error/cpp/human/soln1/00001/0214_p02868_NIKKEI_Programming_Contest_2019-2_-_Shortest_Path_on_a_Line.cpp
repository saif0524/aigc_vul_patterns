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
#define MAX 131072
using namespace std;

pair<pair<int, int>, int> edge[MAX];
map<int, long long> val;

int main(void)
{
	int N, M;
	cin >> N >> M;
	val[1] = 0LL;
	val[N] = 1LL * 998244353 * 998244353;
	for (int i = 0; i < M; i++) cin >> edge[i].first.first >> edge[i].first.second >> edge[i].second;
	sort(edge, edge + M);
	for (auto e : edge)
	{
		if (!e.second) break;
		auto lr = val.lower_bound(e.first.first);
		auto ee = val.lower_bound(e.first.second);
		if (ee->second > lr->second + e.second)
		{
			val[e.first.second] = lr->second + e.second;
			ee = val.upper_bound(e.first.second - 1);
			while (ee->second >= lr->second + e.second && ee != lr)
			{
				auto eee = ee;
				ee--;
				if (eee->first != e.first.second) val.erase(eee);
			}
		}
	}
	if (val[N] < 1LL * 998244353 * 998244353) cout << val[N] << endl;
	else cout << -1 << endl;
	return 0;
}
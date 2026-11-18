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
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    ((void)0);

	int N; cin >> N;
	vector<vector<int> > F(N, vector<int> (10));
	REP(i, N) REP(j, 10) cin >> F[i][j];
	vector<vector<int> > P(N, vector<int> (11));
	REP(i, N) REP(j, 11) cin >> P[i][j];

	ll res = -1e18;
	for (int bit = 1; bit < 1 << 10; bit++) {
		ll sum = 0;
		REP(i, N) {
			int cnt = 0;
			REP(j, 10) {
				if (((bit >> j) & 1) && F[i][j])
					cnt++;
			}
			sum += P[i][cnt];
		}
		res = max(res, sum);
	}

	cout << res << '\n';
    return 0;
}
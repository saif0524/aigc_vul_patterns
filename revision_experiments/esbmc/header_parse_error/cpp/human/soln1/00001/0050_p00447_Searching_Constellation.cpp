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

typedef pair<int, int> P;

P f(P a, P b)
{
	return make_pair(b.first - a.first, b.second - a.second);
}

int main()
{
	int m, n;

	while (true) {
		cin >> m;
		if (m == 0) break;

		vector<P> seiza(m);

		for (int i = 0; i < m; ++i) cin >> seiza[i].first >> seiza[i].second;

		cin >> n;

		vector<P> image(n);

		for (int i = 0; i < n; ++i) cin >> image[i].first >> image[i].second;

		P s0 = seiza[0];

		for (int i = 0; i < n; ++i) {
			int cnt = 1;

			P amount_of_change = f(s0, image[i]);
			for (int j = 1; j < m; ++j) {
				P sj = seiza[j];
				for (int k = 0; k < n; ++k) {
					if (sj.first + amount_of_change.first == image[k].first && sj.second + amount_of_change.second == image[k].second) {
						cnt++;
					}
				}
				if (cnt == m) {
					printf("%d %d\n", amount_of_change.first, amount_of_change.second);
					goto end;
				}
			}
		}
end:;
	}
}
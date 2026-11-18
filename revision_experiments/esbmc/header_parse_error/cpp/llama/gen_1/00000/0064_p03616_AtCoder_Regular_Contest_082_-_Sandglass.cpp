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

int main() {
	int X, K, Q;
	cin >> X;
	cin >> K;
	vector<int> r(K);
	for (int i = 0; i < K; i++)
		cin >> r[i];
	cin >> Q;
	vector<int> t(Q), a(Q), ans(Q);
	for (int i = 0; i < Q; i++) {
		cin >> t[i] >> a[i];
	}
	for (int i = 0; i < Q; i++) {
		int rem = t[i];
		int sand = a[i];
		int j = 0;
		while (j < K && r[j] <= rem) {
			int b = X - sand;
			if (sand > b)
				sand -= (r[j] - (j > 0 ? r[j-1] : 0));
			else
				sand = X - (b - (r[j] - (j > 0 ? r[j-1] : 0)));
			rem -= (r[j] - (j > 0 ? r[j-1] : 0));
			j++;
		}
		if (j % 2 == 1) {
			sand = max(0, sand - rem);
		} else {
			sand = X - max(0, (X - sand) - rem);
		}
		cout << sand << endl;
	}
	return 0;
}
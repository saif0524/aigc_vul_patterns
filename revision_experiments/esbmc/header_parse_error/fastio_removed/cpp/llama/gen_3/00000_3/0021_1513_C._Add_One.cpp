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
const int MOD = 1e9 + 7;

int main() {
	((void)0);
	((void)0);

	int t;
	cin >> t;
	while (t--) {
		string n;
		int m;
		cin >> n >> m;
		long long len = 0;
		for (char d : n) {
			int num = d - '0';
			int cnt = 0;
			for (int i = 0; i < m; i++) {
				num = (num + 1) % 10;
				if (num == 0) cnt++;
			}
			len = (len + cnt + 1) % MOD;
		}
		cout << len << "\n";
	}
	return 0;
}
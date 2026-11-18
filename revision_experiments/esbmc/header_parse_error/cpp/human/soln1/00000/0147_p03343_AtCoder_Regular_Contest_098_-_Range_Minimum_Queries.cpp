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
int n, m, q;
int a[2020];
bool ok(int M) {
	for (int i = 0; i < n; i++) {
		int z = 0, c = 0;
		for (int j = 0, k; j < n; j = k + 1) {
			for (k = j; k < n; k++) {
				if (a[k] < a[i]) {
					break;
				}
				if (a[k] <= a[i] + M) {
					c++;
				}
			}
			if (k - j >= m) {
				z += min(k - j - m + 1, c);
			}
			c = 0;
		}
		if (z >= q) {
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int L = -1, R = 1e9;
	while (L < R - 1) {
		int M = (L + R) / 2;
		if (ok(M)) {
			R = M;
		} else {
			L = M;
		}
	}
	printf("%d\n", R);
	return 0;
}
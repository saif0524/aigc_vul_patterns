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

#define ll long long
#define endl "\n"
#define pb push_back

int main() {
	((void)0);
	((void)0);

	int t;
	cin >> t;
	while (t--) {
		int k, n, m;
		cin >> k >> n >> m;

		vector<int> a(n), b(m);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];

		int i = 0, j = 0;
		vector<int> ans;
		while (i < n || j < m) {
			if (i < n && a[i] == 0) {
				ans.pb(a[i]);
				k++;
				i++;
			} else if (j < m && b[j] == 0) {
				ans.pb(b[j]);
				k++;
				j++;
			} else if (i < n && a[i] <= k) {
				ans.pb(a[i]);
				i++;
			} else if (j < m && b[j] <= k) {
				ans.pb(b[j]);
				j++;
			} else {
				cout << -1 << endl;
				goto next;
			}
		}

		for (int x : ans) { cout << x << " "; }
		cout << endl;

next:
		continue;
	}

	return 0;
}
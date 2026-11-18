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
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = n;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				string sub = s.substr(i, j - i + 1);
				bool good = true;
				while (sub.size() > 1) {
					bool changed = false;
					for (int k = 0; k < sub.size(); k++) {
						if (sub[k] == '>') {
							if (k < sub.size() - 1) {
								sub.erase(k + 1, 1);
								changed = true;
								break;
							}
						} else if (sub[k] == '<') {
							if (k > 0) {
								sub.erase(k - 1, 1);
								changed = true;
								break;
							}
						}
					}
					if (!changed) {
						good = false;
						break;
					}
				}
				if (good) {
					ans = min(ans, n - (j - i + 1));
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
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

const int MAX_N = 2001;

int n;
char a[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++) {
			a[i][j] = s[j - 1];
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == '1' && !vis[i][j]) {
				ans++;
				for (int x = 1; x <= n; x++) {
					if (x <= i && j <= x) {
						if (vis[x][x]) {
							vis[x][x] = false;
						} else {
							vis[x][x] = true;
						}
						for (int y = x + 1; y <= n; y++) {
							if (vis[x][y]) {
								vis[x][y] = false;
							} else {
								vis[x][y] = true;
							}
						}
						for (int y = x - 1; y >= 1; y--) {
							if (vis[x][y]) {
								vis[x][y] = false;
							} else {
								vis[x][y] = true;
							}
						}
						for (int y = 1; y < x; y++) {
							if (vis[y][x]) {
								vis[y][x] = false;
							} else {
								vis[y][x] = true;
							}
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
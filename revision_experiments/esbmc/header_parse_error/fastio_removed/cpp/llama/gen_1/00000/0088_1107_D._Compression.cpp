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
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define N 5205

bool check(int n, int x, vector<vector<int>>& mat) {
	for(int i = 0; i < n; i += x) {
		for(int j = 0; j < n; j += x) {
			int val = mat[i][j];
			for(int k = i; k < i + x; k++) {
				for(int l = j; l < j + x; l++) {
					if(mat[k][l] != val) return false;
				}
			}
		}
	}
	return true;
}

int main() {
	((void)0); ((void)0); ((void)0);
	int n; cin >> n;
	vector<vector<int>> mat(n, vector<int>(n));
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		for(int j = 0; j < n / 4; j++) {
			int val = (s[j] >= '0' && s[j] <= '9') ? s[j] - '0' : s[j] - 'A' + 10;
			for(int k = 0; k < 4; k++) {
				mat[i][j * 4 + k] = (val >> (3 - k)) & 1;
			}
		}
	}
	for(int x = n / 2; x > 0; x--) {
		if(n % x == 0 && check(n, x, mat)) {
			cout << x << '\n';
			return 0;
		}
	}
	cout << 1 << '\n';
	return 0;
}
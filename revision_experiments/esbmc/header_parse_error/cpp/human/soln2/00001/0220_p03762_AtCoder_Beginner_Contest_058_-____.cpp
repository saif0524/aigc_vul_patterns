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

typedef long long int lli;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n, m;
lli x[N];
lli y[N];

int main() {
	cin >> n >> m;

	lli sumX = 0;
	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sort(x, x+n);
	
	for(lli i = 1; i < n; i++) {
		sumX += i*(n-i)*(x[i]-x[i-1]);
		sumX %= MOD;
	}

	lli sumY = 0;
	for(int i = 0; i < m; i++) {
		cin >> y[i];
	}
	sort(y, y+m);
	
	for(lli i = 1; i < m; i++) {
		sumY += i*(m-i)*(y[i]-y[i-1]);
		sumY %= MOD;
	}

	cout << (sumX*sumY)%MOD << endl;

	return 0;
}
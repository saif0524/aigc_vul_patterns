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
 
typedef long long LL;

LL mod = 1000000007;

LL mi (LL x, LL m) {
	// compute pow(x, m-2)
	LL acc = 1;
	LL p = m-2;
	while (p) {
		if (p%2 == 1) {
			acc *= x;
			acc %= m;
		}
		x *= x % m;
		x %= m;
		p >>= 1;
	}
	
	return acc;
}

int main()
{
	LL n;
	cin >> n;

	vector<LL> x(n);

	for (auto &e : x) {
		cin >> e;
	}

	vector<LL> mijs(n-1);

	mijs[0] = 1;
	for (LL i = 1; i < n-1; ++i) {
		mijs[i]=mijs[i-1]+mi(i+1, mod);
		mijs[i]%=mod;
	}

	LL sum = 0;
	for (LL i = 0; i < n-1; ++i) {
		sum += (x[i+1]-x[i])*mijs[i] % mod;
		sum %= mod;
	}

	for (LL i = 1; i <= n-1; ++i) {
		sum *= i;
		sum %= mod;
	}

	cout << sum << "\n";

}
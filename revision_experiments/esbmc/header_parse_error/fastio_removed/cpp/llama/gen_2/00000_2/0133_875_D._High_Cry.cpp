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
#define ld long double
#define ar array

const int mxN=2e5;
int n, a[mxN];

int main() {
	((void)0);
	((void)0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	ll cnt=0;
	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			int or_=a[i]|a[j];
			bool ok=1;
			for(int k=i; k<=j; ++k)
				if((or_&a[k])!=or_)
					ok=0;
			if(ok)
				++cnt;
		}
	}
	cout << cnt;
	return 0;
}
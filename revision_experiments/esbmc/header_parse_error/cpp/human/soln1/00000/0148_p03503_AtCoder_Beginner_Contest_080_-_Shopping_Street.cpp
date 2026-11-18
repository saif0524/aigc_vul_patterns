// C - Shopping Street
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
using vi = vector<int>;
using vvi = vector<vi>;
#define rp(i,s,e) for(int i=(int)(s);i<(int)(e);++i)

int main(){
	int n; cin>>n;
	vvi F(n, vi(10));
	rp(i, 0, n) rp(j, 0, 10) cin>>F[i][j];
	vvi P(n, vi(10+1));
	rp(i, 0, n) rp(j, 0, 10+1) cin>>P[i][j];
	int64_t ans = -10000000*100;
	rp(i, 1, 1<<10){
		int64_t s = 0;
		rp(j, 0, n){
			int cj = 0;
			rp(k, 0, 10) if(i>>k & 1 && F[j][k]) cj++;
			s += P[j][cj];
		}
		ans = max(ans, s);
	}
	cout<< ans <<endl;
}
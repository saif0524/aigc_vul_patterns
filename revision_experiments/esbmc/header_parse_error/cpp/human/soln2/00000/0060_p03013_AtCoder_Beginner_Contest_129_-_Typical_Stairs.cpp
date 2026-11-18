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
 
const int mod = 1e9 + 7;
int32_t main() {
	int n, m; cin>>n>>m;
	vector<int> dp(n + 1);
	map<int, int> broken;
	for(int i = 0; i < m; i++){
		int x; cin>>x;
		broken[x] = 1;
	}
	dp[0] = 1;
	dp[1] = (broken[1] ? 0 : 1);
	for(int i = 2; i <= n; ++i){
		if(broken[i]) dp[i] = 0;
		else dp[i] = (dp[i-1] + dp[i-2]) % mod;
	}
	cout<<dp[n]<<endl;
}
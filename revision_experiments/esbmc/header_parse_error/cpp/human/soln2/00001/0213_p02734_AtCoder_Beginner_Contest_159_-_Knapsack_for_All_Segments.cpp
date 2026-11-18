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
#define INF 0x3f3f3f3f
const int MOD=998244353;
const double eps=1e-8;
typedef long long ll;
//orz yht
using namespace std;
ll n,s,a[3005];
ll dp[3005],ans;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>s;
	dp[0]=1;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		if(s>=a[i])
		ans=(ans+dp[s-a[i]]*(n-i))%MOD;
		for(ll j=s-a[i]-1;j>=0;j--)
		dp[j+a[i]]=(dp[j+a[i]]+dp[j])%MOD;
		dp[0]++;
	}
	cout<<ans;
	return 0;
}
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
#define int long long
using namespace std;
 
signed main(){
	int a,b;
	cin>>a>>b;
	vector<int>c(a);
	vector<int>d(b);
	for(int e=0;e<a;e++)cin>>c[e];
	for(int e=0;e<b;e++)cin>>d[e];
	vector<vector<int>>dp(a+1,vector<int>(b+1));
	for(int f=0;f<a;f++){
		int x=INT_MAX;
		for(int g=f;g<b;g++){
			x=min(x,dp[f][g]);
			dp[f+1][g+1]=x+c[f]*d[g];
			}
		}
		int s=INT_MAX;
		for(int x:dp[a]){
			if(x!=0&&x<s)s=x;
			}
			cout<<s<<endl;
}
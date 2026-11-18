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
#define INF 1000000007
using namespace std;

int n,m,a[50],ans=INF;
vector<int> v[50];

inline void dfs(int loc,int mask1,int cost)
{
	int mask2=mask1;
	if(!((mask1>>loc)&1ll)){
		cost+=a[loc];
		mask1|=(1ll<<(loc));
	}
	for(int i=0;i<v[loc].size();i++){
		if(!(mask1&(1ll<<(v[loc][i])))){
			cost+=a[v[loc][i]];
			mask1|=(1ll<<(v[loc][i]));
		}
	}
	if(cost>=ans) return;
	if(loc==n-1){
		ans=cost;
		return;
	}
	for(int i=0;i<v[loc].size();i++){
		if(!(mask2&(1ll<<(v[loc][i])))){
			dfs(v[loc][i],mask1,cost);
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(0,0,0);
	cout<<ans<<endl;
	return 0;
}
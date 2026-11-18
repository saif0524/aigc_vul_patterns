#pragma GCC optimize(2)
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
#define INF 1000000007
using namespace std;

int n,m,dp[100010][20],val[100010];
int num[20][20];
vector<int> v;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		num[a][b]=num[b][a]=c;
	}
	val[0]=0;
	for(int i=1;i<(1<<n);i++){
		v.clear();
		for(int j=1;j<=n;j++) if(i&(1<<(j-1))){
			v.push_back(j); 
		}
		val[i]=val[i^(1<<(v[0]-1))];
		for(int j=1;j<v.size();j++){
			val[i]+=num[v[0]][v[j]];
		}
	}
	for(int i=0;i<(1<<n);i++) for(int j=1;j<=n;j++) dp[i][j]=INF;
	for(int i=1;i<(1<<n);i++){
		if(i==1) dp[i][1]=0;
		for(int j=1;j<=n;j++) if(i&(1<<(j-1))){
			int xx=(1<<(j-1));
			for(int k=1;k<=n;k++) if((!(i&(1<<(k-1))))&&(num[j][k]!=0)){
				int yy=(1<<(k-1));
				int sum=val[i^xx^yy]-val[i^xx];
				dp[i^yy][k]=min(dp[i^yy][k],dp[i][j]+sum);
			}
			int zz=((1<<n)-1)^i;
			for(int mask=zz;mask>0;mask=(mask-1)&zz){
				int sum=val[i^xx^mask]-val[i^xx]-val[mask];
				dp[i^mask][j]=min(dp[i^mask][j],dp[i][j]+sum);
			}
		}
	}
	cout<<dp[(1<<n)-1][n]<<endl;
	return 0;
}
#define _USE_MATH_DEFINES
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

typedef long long ll;
typedef long double ld;


const int N=102;
int a[N],b[N];
int dp[N][N*N][N]; // step, volume, k, max water
int n;
int watersum,volumesum;

int main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i]>>b[i];
	for(int i=0;i<n;++i)watersum+=b[i];
	for(int i=0;i<n;++i)volumesum+=a[i];
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<=volumesum;++j)
			for(int k=0;k<=n;++k)
				if(~dp[i][j][k]){
					dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
					dp[i+1][j+a[i]][k+1]=max(dp[i+1][j+a[i]][k+1],dp[i][j][k]+b[i]);
				}
	vector<ld>res(n+1);
	for(int k=1;k<=n;++k)
		for(int j=0;j<=volumesum;++j)
			if(~dp[n][j][k])
				res[k]=max(res[k],min(ld(j),dp[n][j][k]+ld(watersum-dp[n][j][k])/2));
	for(int k=1;k<=n;++k)cout<<fixed<<setprecision(10)<<res[k]<<" ";cout<<endl;
			
}
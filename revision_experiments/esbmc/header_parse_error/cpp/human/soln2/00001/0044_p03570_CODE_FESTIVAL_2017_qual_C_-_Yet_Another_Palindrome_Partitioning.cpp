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
const int N=2e5+10;
map<int,int> dp;
int n,cnt[N][26],state[N];
char s[N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++){
		for (int j=0;j<26;j++) cnt[i][j]=cnt[i-1][j];
		cnt[i][s[i]-'a']^=1;
		for (int j=0;j<26;j++) state[i]|=(cnt[i][j]<<j);
	}
	dp[0]=0;
	for (int i=1;i<=n;i++){
		int now=state[i];
		if (!dp.count(now)) dp[now]=1e9;
		int v=dp[now]+1;
		for (int j=0;j<26;j++)
			if (dp.count(now^(1<<j))) v=min(v,dp[now^(1<<j)]+1);		
		dp[now]=min(dp[now],v);
		if (i==n) printf("%d\n",v);
	}
	return 0;
}
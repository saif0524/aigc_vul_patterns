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
long long dp[5005];
int tag[5005],s[5005];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		scanf("%d",&tag[i]);
		for (int i=1;i<=n;i++)
		scanf("%d",&s[i]);
		for (int i=1;i<=n;i++)
		{
			dp[i]=0;
			for (int j=i-1;j>0;j--)
			{
				if (tag[i]==tag[j])
				continue;
				long long tmp=dp[i]+abs(s[i]-s[j]);
				dp[i]=max(dp[i],dp[j]+abs(s[i]-s[j]));
				dp[j]=max(dp[j],tmp);
			}
		}
		printf("%I64d\n",*max_element(dp+1,dp+n+1));
	}
}
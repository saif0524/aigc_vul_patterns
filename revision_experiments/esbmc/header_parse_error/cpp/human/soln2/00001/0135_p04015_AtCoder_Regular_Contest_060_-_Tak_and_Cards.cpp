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
const int MAXN = 50;
int n, avg, a[MAXN+5];
long long memo[MAXN+5][MAXN*MAXN+5];
int main()
{
	scanf("%d%d", &n, &avg);  
	for(int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	memo[0][0] = 1;
	for(int i=1; i<=n; i++)
		for(int j=i-1; j>=0; j--)
			for(int k=0; k<=j*MAXN; k++)
				memo[j+1][k+a[i]] += memo[j][k];
	long long ans = 0;
	for(int i=1; i<=n; i++)
		ans += memo[i][i*avg];
	printf("%lld", ans);
}
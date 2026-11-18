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

const int N = 110,mod=1e9+7;

typedef long long ll;

int a[N];
ll s[110000];
ll f[110][110000];
int main()
{
	ll n,k;
	cin>>n>>k;

	
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i =0;i<=k;i++) f[1][i] = (i<=a[1])? 1:0;
	for(int i=2;i<=n;i++)
	{	memset(s,0,sizeof(s));
		s[0]=f[i-1][0];
		for(int j=1;j<=k;j++)
		{
			s[j]=s[j-1]+f[i-1][j];
		}
		for(int j=k;j>=0;j--)
		{
			if(j-a[i]-1>=0) f[i][j]=s[j]-s[j-a[i]-1];
			else f[i][j]=s[j];
			f[i][j]%=mod;
		}
	}
	cout<<f[n][k]<<endl;
 
}
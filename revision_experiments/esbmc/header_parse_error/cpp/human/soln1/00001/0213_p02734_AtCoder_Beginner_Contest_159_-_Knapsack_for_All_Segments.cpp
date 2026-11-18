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
using ll=long long;
const ll mod=998244353;
int n,s,a[3010],f[3010];
ll ans;
int main(){
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		for(int j=s;j>a[i];j--)
			j==s && ((ans+=1ll*f[j-a[i]]*(n-i+1))%=mod),
			(f[j]+=f[j-a[i]])%=mod;
		(f[a[i]]+=i)%=mod;
		if(a[i]==s)(ans+=1ll*i*(n-i+1))%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}
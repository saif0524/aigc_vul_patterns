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
const int N=2005;
int d[N],a[N],c[N],b[N],n,k,q,ans=1000000000;
int solve(int x){
	int cnt=0,tot=0;
	for (int i=1;i<=n+1;i++){
		if (a[i]<x){
			if (cnt>=k){ 
				std::sort(c+1,c+cnt+1);
				for (int j=1;j+k-1<=cnt;j++) d[++tot]=c[j];
			}
			cnt=0;
		}else c[++cnt]=a[i];
	}
	if (tot<q) return ans;
	std::sort(d+1,d+tot+1);
	return d[q]-d[1];
}
int main(){
	scanf("%d%d%d",&n,&k,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	std::sort(b+1,b+n+1);
	for (int i=1;i<=n;i++)
		ans=std::min(ans,solve(b[i]));
	printf("%d\n",ans);
}
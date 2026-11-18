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
int a[55],b[55],c[55],d[55],n,m,i,j,num,s,mins=0x7fffffff;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for(i=1;i<=m;i++) scanf("%d%d",&c[i],&d[i]);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			s=abs(a[i]-c[j])+abs(b[i]-d[j]);
			if(s<mins) mins=s,num=j;
		}
		printf("%d\n",num);
		mins=0x7fffffff;
	}
	return 0;
}
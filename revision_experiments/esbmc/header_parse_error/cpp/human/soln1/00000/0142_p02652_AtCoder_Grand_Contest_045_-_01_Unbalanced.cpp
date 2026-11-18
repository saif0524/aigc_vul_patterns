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
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=1e6+7,INF=0x3f3f3f3f,sgn[]={-1,1};
char a[N];
int n,s[N],nxt[N];
int solve(int x,int cnt=0){
	int w=0;
	FOR(i,1,n){
		if(a[i]=='?'&&cnt+2+nxt[i]<=x)cnt+=2;
		w=min(w,s[i]+cnt);
	}
	return x-w;
}
int main(){
	scanf("%s",a+1),n=strlen(a+1),nxt[n+1]=-INF;
	FOR(i,1,n)s[i]=s[i-1]+sgn[a[i]=='1'];
	ROF(i,n,0)nxt[i]=max(nxt[i+1],s[i]);
	cout<<min(solve(nxt[0]),solve(nxt[0]+1));
	return 0;
}
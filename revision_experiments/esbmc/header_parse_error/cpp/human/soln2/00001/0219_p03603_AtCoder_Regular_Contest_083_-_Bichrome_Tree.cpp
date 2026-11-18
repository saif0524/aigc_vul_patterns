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
#define N 5005
using namespace std;
vector<int> G[N];
int n,f[N],a[N],b[N][2];
void GG(){ printf("IMPOSSIBLE"); exit(0);}
void dfs(int t)
{
	int i,j,x,S=0,C=0;
	if(!G[t].size()){ b[t][1]=a[t]; return ;}
	for(i=0;i<G[t].size();i++)
		dfs(G[t][i]),S+=b[G[t][i]][0],C+=b[G[t][i]][1];
	if(S>a[t]) GG();
	for(j=0;j<=a[t]-S;j++) f[j]=0;
	f[0]=1;
	for(i=0;i<G[t].size();i++){
		x=b[G[t][i]][1]-b[G[t][i]][0];
		for(j=a[t]-S;j>=x;j--) f[j]|=f[j-x];
	  }
	for(j=a[t]-S;j>=0;j--) if(f[j]) break;
	b[t][0]=a[t],b[t][1]=C-j;
	if(b[t][0]>b[t][1]) swap(b[t][0],b[t][1]);
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=2;i<=n;i++)
		scanf("%d",&f[i]),G[f[i]].push_back(i);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1);
	printf("POSSIBLE");
	return 0;
}
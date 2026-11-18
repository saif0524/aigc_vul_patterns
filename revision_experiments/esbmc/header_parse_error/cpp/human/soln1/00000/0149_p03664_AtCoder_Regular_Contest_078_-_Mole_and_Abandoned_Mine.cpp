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

inline int read() {
	int res=0,fh=1;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-')fh=-1,ch=getchar();
	while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
	return fh*res;
}

const int maxn=16;
int n,m,mxs,sum[(1<<16)+12],a[maxn][maxn];
int f[(1<<maxn)][maxn];
inline int Max(int a,int b){return a>b?a:b;}

int main(){
	n=read(),m=read();
	mxs=(1<<n)-1;
	for(int i=1;i<=m;i++){
		int x=read()-1,y=read()-1,z=read();
		a[x][y]=a[y][x]=z;
	}
	for(int i=0;i<=mxs;i++){
		sum[i]=0;
		for(int j=0;j<n;j++)
			if((i&(1<<j)))
				for(int k=j+1;k<n;k++)
					if((i&(1<<k))) sum[i]+=a[j][k];
	}
	memset(f,-1,sizeof f);
	f[1][0]=0;
	for(int i=1;i<=mxs;i+=2){
		for(int j=0;j<n;j++){
			if(f[i][j]==-1) continue;
			if(!(i&(1<<j))) continue;
			for(int k=0;k<n;k++)
				if(a[j][k]&&(!(i&(1<<k))))
					f[i|(1<<k)][k]=Max(f[i|(1<<k)][k],f[i][j]+a[j][k]);
			int c=(mxs-i)|(1<<j);
			for(int k=c;k>=0;k=(k==0?-1:(k-1)&c))
				f[i|k][j]=Max(f[i][j]+sum[k],f[i|k][j]);
		}
	}
	int ans=0;
	for(int i=(mxs>>1)+2;i<=mxs;i+=2)
		ans=Max(ans,f[i][n-1]);
	printf("%d\n",sum[mxs]-ans);
	return 0;
}
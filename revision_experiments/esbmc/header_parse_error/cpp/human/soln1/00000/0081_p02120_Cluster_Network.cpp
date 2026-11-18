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

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

vector<int> G[1000000];
vector<pair<int, int> > bridge;
vector<int> articulation;
int ord[1000000], low[1000000];
bool vis[1000000];

int W[111111];

int al=0;
int sum[111111];
int ans[111111];
void dfs(int v, int p, int &k)
{
	vis[v] = true;
    sum[v]=W[v];
	ord[v] = k++;
	low[v] = ord[v];

	bool isArticulation = false;
	int ct = 0;

	vint g;
	for (int i = 0; i < G[v].size(); i++){
		if (!vis[G[v][i]]){
			ct++;
			g.pb(G[v][i]);
			dfs(G[v][i], v, k);
			sum[v]+=sum[G[v][i]];
			low[v] = min(low[v], low[G[v][i]]);
			if (~p && ord[v] <= low[G[v][i]]) isArticulation = true;
		}
		else if (G[v][i] != p){
			low[v] = min(low[v], ord[G[v][i]]);
		}
	}

	if (p == -1 && ct > 1) isArticulation = true;
    if(isArticulation){
        int s=0;
        for(auto u:g){
            if(low[u]>=ord[v])chmax(ans[v],sum[u]);
            else s+=sum[u];
        }
        chmax(ans[v],al-sum[v]+s);
    }
    else{
        ans[v]=al-W[v];
    }
}



signed main(){
    int N,M;scanf("%lld%lld",&N,&M);
    rep(i,N)scanf("%lld",&W[i]);

    rep(i,M){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }
    al=accumulate(W,W+N,0ll);
    int k=0;
    dfs(0,-1,k);

    rep(i,N)printf("%lld\n",ans[i]);
    return 0;
}
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

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

ll n,k,inv,x[MAX],y[MAX],bit[MAX],res,id;

inline void upd(int i,int z){
	for(; i<=n; i+=(i&-i))bit[i]+=z;
}
int ret;
inline int que(int i){
	i--;
	ret = 0;
	for(; i> 0; i-=(i&-i))ret+=bit[i];
	return ret;
}

priority_queue<int, vector<int> ,greater<int> > pq;
priority_queue<pii, vector<pii> ,greater<pii> > tmp;
vector<int> ans;

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n)cin>>y[i], x[y[i]] = i;
    rap(i,n,1)inv+=que(x[i]), upd(x[i],1);
    if(inv<=k)rep(i,1,n)cout<<y[i]<<endl;
    else {
    	k = inv - k;
    	rep(i,1,n)pq.push(i);
    	rep(i,1,n){
    		while(!tmp.empty()&&que(x[tmp.top().se])<=k)pq.push(tmp.top().se), tmp.pop();
    		while(!pq.empty()){
    			id = pq.top(); pq.pop();
    			res = que(x[id]);
    			if(res>k)tmp.push({x[id],id});
    			else {
    				ans.pb(id);
    				k-=res;
    				upd(x[id],-1);
    				break;
				}
			}
		}
		for(auto i:ans)cout<<i<<endl;
	}
	return 0;
}
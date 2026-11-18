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

int N,Q;
int A[222222],B[222222];

signed main(){
    scanf("%lld%lld",&N,&Q);
    N*=2;
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,N)scanf("%lld",&B[i]);

    multiset<int>x,y;
    int sumx=0;
    int base=accumulate(A,A+N,0ll);
    for(int i=1;i+1<N;i++){
        if(A[i]<=B[i]){
            x.insert(B[i]-A[i]);
            sumx+=B[i]-A[i];
        }
        else{
            y.insert(B[i]-A[i]);
        }
    }

    while(Q--){
        int p,a,b;
        scanf("%lld%lld%lld",&p,&a,&b);
        p--;

        base-=A[p];
        if(1<=p&&p+1<N){
            if(A[p]<=B[p]){
                sumx-=B[p]-A[p];
                auto it=x.find(B[p]-A[p]);
                x.erase(it);
            }
            else{
                auto it=y.find(B[p]-A[p]);
                y.erase(it);
            }
        }

        A[p]=a;B[p]=b;
        base+=A[p];
        if(1<=p&&p+1<N){
            if(A[p]<=B[p]){
                x.insert(B[p]-A[p]);
                sumx+=B[p]-A[p];
            }
            else{
                y.insert(B[p]-A[p]);
            }
        }

        int ans=0;
        if(x.size()%2==0){
            ans=sumx;
        }
        else{
            ans=sumx-*x.begin();
            chmax(ans,sumx+*y.rbegin());
        }
        printf("%lld\n",ans+base);
    }
    return 0;
}
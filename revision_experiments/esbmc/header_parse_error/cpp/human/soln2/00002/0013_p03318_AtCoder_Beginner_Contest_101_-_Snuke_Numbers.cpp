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
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

ll sn(ll n){
    ll ans = 0;
    while(n > 0){
        ans += n%10;
        n /= 10;
    }
    return ans;
}

int main(){
    cin>>K;
    N = 1;
    vec bit10(19,1);
    reps(i,1,19) bit10[i] = bit10[i-1] * 10;
    rep(i,K){
        cout<<N<<endl;
        ++N;
        ll next = N;
        for(ll m = N, d = 0; m >= 0; m /= 10){
            ll temp = bit10[d+1] * (N/bit10[d+1] + 1) - 1;
            if(next * sn(temp) > temp * sn(next)) next = temp;
            ++d;
            if(m == 0) break;
            //cout<<i<<' '<<m<<endl;
        }
        N = next;
    }
}
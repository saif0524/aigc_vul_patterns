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

typedef long long ll;
const int MOD = 998244353;

ll modpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    ((void)0);
    ((void)0);
    int N;
    cin >> N;
    vector<int> h(2*N);
    for(auto &x: h) cin >> x;
    sort(h.begin(), h.end());
    ll fact[100005] = {1};
    for(int i=1;i<=2*N;i++) fact[i] = fact[i-1] * i % MOD;
    ll inv_fact[100005] = {1, 1};
    for(int i=2;i<=2*N;i++) inv_fact[i] = MOD - MOD/i * inv_fact[MOD%i] % MOD;
    for(int i=2;i<=2*N;i++) inv_fact[i] = inv_fact[i] * inv_fact[i-1] % MOD;
    ll ans = fact[2*N];
    for(int i=0;i<2*N-1;i+=2){
        if(h[i] == h[i+1]){
            cout << 0;
            return 0;
        }
        ans = ans * inv_fact[2] % MOD;
    }
    cout << ans;
}
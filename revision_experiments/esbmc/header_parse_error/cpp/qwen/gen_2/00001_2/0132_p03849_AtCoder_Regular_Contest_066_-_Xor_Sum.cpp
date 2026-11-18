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

const ll MOD = 1e9 + 7;

ll fastpow(ll b, ll e) {
    ll ans = 1;
    while (e > 0) {
        if (e & 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ans;
}

int main(){
    ll N;
    cin >> N;
    ll ans = 0;
    for(ll i=0; (1LL<<i) - 1 <= N; ++i){
        ll block = (1LL<<(i+1)) - 1;
        ll complete = N / block;
        ll rem = N % block;
        if(rem < (1LL<<i)){
            ans = (ans + (complete % MOD) * fastpow(3LL, i) % MOD) % MOD;
        }else{
            ans = (ans + ((complete + 1) % MOD) * fastpow(3LL, i) % MOD) % MOD;
        }
    }
    cout << ans;
}
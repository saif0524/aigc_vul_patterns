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
const int MOD = 1e9 + 7;

ll power(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main(){
    ((void)0);
    ((void)0);
    ll n;
    cin >> n;
    ll total_perms = power(2LL, n-1, MOD);
    ll acyclic = (n % 2 == 1) ? 1 : 2;
    for(ll k=3; k<=n; k+=2){
        ll cycles = power(n, k, MOD);
        for(ll j=1; j<=k-2; j++){
            cycles = (cycles * (n-1)) % MOD;
        }
        cycles = (cycles * power(k, MOD-2, MOD)) % MOD;
        cycles = (cycles * power(2, k-1, MOD)) % MOD;
        cyclic = (cyclic + cycles) % MOD;
    }
    ll result = (total_perms - acyclic + MOD) % MOD;
    cout << result;
    return 0;
}
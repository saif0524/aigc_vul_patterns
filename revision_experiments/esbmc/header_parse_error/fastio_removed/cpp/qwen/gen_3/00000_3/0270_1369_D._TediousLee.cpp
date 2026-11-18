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

ll power_mod(ll base, ll exp) {
    ll result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) result = result * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return result;
}

int main(){
    ((void)0);
    ((void)0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n == 1 || n == 2){
            cout << 0 << "\n";
            continue;
        }
        ll ans = (power_mod(3, n-2) - 1 + MOD) % MOD;
        ans = (ans * 4) % MOD;
        cout << ans << "\n";
    }
}
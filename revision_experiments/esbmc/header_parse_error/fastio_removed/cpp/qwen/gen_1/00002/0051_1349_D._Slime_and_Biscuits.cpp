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

const int MOD = 998244353;

int modPow(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1) res = (1LL * res * x) % MOD;
        x = (1LL * x * x) % MOD;
        y >>= 1;
    }
    return res;
}

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<int> a(n);
    int total = 0;
    for(int &x: a){
        cin >> x;
        total += x;
    }
    if(total == 0){
        cout << 0;
        return 0;
    }
    if(n == 2){
        cout << (1LL * a[0] * a[1]) % MOD;
        return 0;
    }
    vector<int> fact(total + 1, 1);
    vector<int> invFact(total + 1, 1);
    for(int i = 2; i <= total; i++){
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
        invFact[i] = modPow(fact[i], MOD - 2);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == total){
            continue;
        }
        int ways = fact[total];
        for(int j = 0; j < n; j++){
            if(a[j] > 0){
                ways = (1LL * ways * invFact[a[j]]) % MOD;
            }
        }
        int contrib = (1LL * ways * (total - a[i]) * modPow(n - 1, total - a[i] - 1)) % MOD;
        ans = (ans + contrib) % MOD;
    }
    cout << ans;
}
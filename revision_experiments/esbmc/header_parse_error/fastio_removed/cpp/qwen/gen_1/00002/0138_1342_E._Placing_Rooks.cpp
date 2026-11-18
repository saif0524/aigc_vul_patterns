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

long long powmod(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

long long inv(long long x) {
    return powmod(x, MOD - 2);
}

int main(){
    ((void)0);
    ((void)0);
    long long n, k;
    cin >> n >> k;
    if(k < n-1 || k > n*(n-1)/2){
        cout << 0;
        return 0;
    }
    long long ans = powmod(n, n);
    for(long long i = 1; i <= n; i++)
        ans = (ans * inv(i)) % MOD;
    long long ways = 1;
    for(long long i = n-1; i > n-1-k; i--)
        ways = (ways * i) % MOD;
    for(long long i = 0; i < k-(n-1); i++)
        ways = (ways * (n-1-i)) % MOD;
    ans = (ans * ways) % MOD;
    ans = (ans * inv(powmod(2, k-(n-1)))) % MOD;
    cout << ans;
}
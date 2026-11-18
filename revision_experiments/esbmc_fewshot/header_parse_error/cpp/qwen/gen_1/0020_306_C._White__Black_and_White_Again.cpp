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

const int MOD = 1000000009;

long long fact[4005], inv_fact[4005];

long long mod_pow(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

void precompute(int max_n) {
    fact= 1;
    for (int i =1; i <= max_n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[max_n] = mod_pow(fact[max_n], MOD -2);
    for (int i = max_n - 1; i >= 0; --i) {
        inv_fact[i] = (inv_fact[i +1] * (i + 1)) % MOD;
    }
}

long long comb(int n, int k) {
    if (k > n) return 0;
    return (((fact[n] * inv_fact[k]) % MOD) * inv_fact[n - k]) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, w, b;
    cin >> n >> w >> b;
    
    precompute(n + w + b);
    
    long long result = 0;
    
    for (int w1= 1; w1 <= w - 1; ++w1) {
        for (int b1= 1; b1 <= b; ++b1) {
            int w2 = w - w1;
            if (w1 + b1 + w2 == n) {
                long long ways = comb(w, w1) * comb(b, b1) % MOD * comb(w2, w2) % MOD;
                result = (result + ways) % MOD;
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}
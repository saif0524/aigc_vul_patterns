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
const int MOD = 1000000007;
const int MAXN = 100005;
const int MAXQ = 100005;

ll fib[2*MAXN];
ll BIT1[MAXN];
ll BIT2[MAXN];
int n, m;

void add(ll BIT[], int idx, ll val) {
    while (idx <= n) {
        BIT[idx] = (BIT[idx] + val) % MOD;
        idx += (idx & (-idx));
    }
}

ll sum(ll BIT[], int idx) {
    ll res = 0;
    while (idx > 0) {
        res = (res + BIT[idx]) % MOD;
        idx -= (idx & (-idx));
    }
    return res;
}

int main(){
    ((void)0);
    ((void)0);
    cin >> n >> m;
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i < 2*MAXN; i++) fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        add(BIT1, i, a);
        add(BIT2, i, a*a);
    }
    while(m--){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            ll x;
            cin >> x;
            add(BIT1, l, x);
            add(BIT1, r+1, -x);
            add(BIT2, l, x*x);
            add(BIT2, r+1, -x*x);
        }
        else{
            ll sum1 = sum(BIT1, r) - sum(BIT1, l-1);
            ll sum2 = sum(BIT2, r) - sum(BIT2, l-1);
            ll num = (sum1*sum1 - sum2 + MOD) % MOD;
            ll den = 2;
            num = (num * den) % MOD;
            num = (num + MOD) % MOD;
            cout << fib[num] << "\n";
        }
    }
}
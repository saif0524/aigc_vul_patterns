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

vector<vector<ll>> dp;

ll solve(int pos, int prev, const vector<int>& c, const vector<int>& b) {
    if (pos == c.size()) return 1;
    if (dp[pos][prev] != -1) return dp[pos][prev];
    ll res = 0;
    int low = 0, high = c[pos];
    if (pos > 0) low = max(low, prev + b[pos-1] - c[pos]);
    if (pos < c.size() - 1) high = min(high, (prev + b[pos]) / 2);
    for (int val = low; val <= high; ++val) {
        res = (res + solve(pos + 1, val, c, b)) % MOD;
    }
    return dp[pos][prev] = res;
}

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<int> c(n);
    for(int &x : c) cin >> x;
    vector<int> b(n-1);
    for(int &x : b) cin >> x;
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        dp.assign(n, vector<ll>(c[0] + 1, -1));
        ll res = 0;
        for(int i=max(0, x); i<=c[0]; ++i){
            res = (res + solve(1, i, c, b)) % MOD;
        }
        cout << res << "\n";
    }
}
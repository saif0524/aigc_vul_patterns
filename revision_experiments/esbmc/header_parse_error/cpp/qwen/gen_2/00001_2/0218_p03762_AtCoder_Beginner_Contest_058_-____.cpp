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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> x(n);
    vector<ll> y(m);
    for(auto &i: x) cin >> i;
    for(auto &i: y) cin >> i;
    vector<ll> dx(n-1);
    vector<ll> dy(m-1);
    for(int i=1; i<n; i++){
        dx[i-1] = x[i] - x[i-1];
    }
    for(int i=1; i<m; i++){
        dy[i-1] = y[i] - y[i-1];
    }
    ll sum_dx = 0;
    for(int i=0; i<n-1; i++){
        sum_dx = (sum_dx + dx[i]*(n-i-1)) % MOD;
    }
    ll ans = 0;
    for(int i=0; i<m-1; i++){
        ll tmp = sum_dx * dy[i] % MOD;
        ans = (ans + tmp * (m-i-1)) % MOD;
        sum_dx = (sum_dx - dx[i] * (n-i-1) + MOD) % MOD;
    }
    cout << ans;
}
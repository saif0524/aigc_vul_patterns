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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(in) in.begin(),in.end()
using ll = long long;
using namespace std;
 
void chmax(ll &a, ll b) { if (a < b) a = b; return; }
using pll = pair<ll,ll>;
 
int main() {
    int n; cin >> n;
    vector<pll> a(n); rep(i,n) cin >> a[i].first, a[i].second = i;
    sort(all(a),greater<pll>());
 
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    rep(i,n) rep(j,n-i){
        chmax(dp[i+1][j], dp[i][j] + a[i+j].first * abs(a[i+j].second - i));
        chmax(dp[i][j+1], dp[i][j] + a[i+j].first * abs((n-1-j) - a[i+j].second));
    }
    ll ans = 0;
    rep(i,n+1) chmax(ans, dp[i][n-i]);
    cout << ans << endl;
}
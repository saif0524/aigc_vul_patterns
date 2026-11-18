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
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef pair<int, int> pi;
typedef pair<long long, long long> pll;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ALL(x) x.begin(), x.end()

ll f(ll x) {
    ll ans = 0;
    while (x) {
        if (x % 2) ans++;
        x /= 2;
    }
    return ans;
}

int main() {
    ((void)0);
    ((void)0);
    ((void)0);
    ll n;
    cin >> n;
    vll arr(n);
    REP(i, n) cin >> arr[i];
    ll ans = 0;
    REP(i, n) {
        FOR(j, i + 1, n) {
            if (f(arr[i]) == f(arr[j])) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
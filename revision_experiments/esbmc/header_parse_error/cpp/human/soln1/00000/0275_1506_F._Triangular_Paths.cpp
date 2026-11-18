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

pair<int, int> a[200010];

int calc(int l, int r, int x, int y) {
    if (x == l && y == r) {
        return 0;
    }
    int t = ((x + y) % 2) ? 0 : 1;

    if(x - l == y - r){
        return t * (x - l);
    } else {
        if((l + r)  % 2 == 0){
            return (x - l - y + r) / 2 ;
        } else {
            return (x - l - y + r) / 2 + +  (x - l - y + r) % 2;
        }
    }

}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first;
    for (int i = 1; i <= n; i++)
        cin >> a[i].second;
    sort(a + 1, a + 1 + n);
    int l = 1, r = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += calc(l, r, a[i].first, a[i].second);
        l = a[i].first;
        r = a[i].second;
    }
    cout << ans<<'\n';

}

int main() {
    std::ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }

}//
// Created by sWX952464 on 3/26/2021.
//

///13 2 10 50 1 28 37 32 30 46 19 47 33 41 24 34 27 42 49 18 9 48 23 35 31 8 7 12 6 5 3 22 43 36 11 40 26 4 44 17 39 38 15 14 25 16 29 20 21 45
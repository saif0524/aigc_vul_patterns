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

void solve(vector<int>& a, vector<int>& depth, int l, int r, int d) {
    if (l > r) return;
    int max_idx = l;
    for (int i = l + 1; i <= r; ++i) {
        if (a[i] > a[max_idx]) {
            max_idx = i;
        }
    }
    depth[a[max_idx] - 1] = d;
    solve(a, depth, l, max_idx - 1, d + 1);
    solve(a, depth, max_idx + 1, r, d + 1);
}

int main(){
    ((void)0);
    ((void)0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &x: a) cin >> x;
        vector<int> depth(n, 0);
        solve(a, depth, 0, n-1, 0);
        for(auto &x: depth) cout << x << ' ';
        cout << '\n';
    }
}
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

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == ')') {
            ans.push_back(0);
        } else if (s[i] == '#') {
            if (i == n - 1) {
                ans.push_back(0);
            } else {
                ans.push_back(max(1, ans.back() + 1));
            }
        }
    }
    reverse(ans.begin(), ans.end());
    int cnt = 0, r = 0, p = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') ++p;
        else if (s[i] == ')') ++r;
        else {
            r += ans[p];
            ++cnt;
        }
        if (r > p) {
            cout << -1 << '\n';
            return;
        }
    }
    if (p != r) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < cnt; ++i) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
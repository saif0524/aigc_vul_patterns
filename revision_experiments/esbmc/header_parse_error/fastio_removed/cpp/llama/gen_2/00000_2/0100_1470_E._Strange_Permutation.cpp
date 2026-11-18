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

int a[30005];
vector<vector<int>> ans;

void solve() {
    int n, c, q;
    cin >> n >> c >> q;
    ans.clear();
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> tmp = a;
    tmp.insert(tmp.begin(), 0);
    ans.push_back(tmp);
    for (int len = 1; len <= c; len++) {
        for (int i = 1; i <= n - len; i++) {
            tmp = a;
            tmp.insert(tmp.begin(), 0);
            reverse(tmp.begin() + i, tmp.begin() + i + len);
            sort(ans.begin(), ans.end());
            if (find(ans.begin(), ans.end(), tmp) == ans.end()) {
                ans.push_back(tmp);
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (y > ans.size()) {
            cout << -1 << "\n";
            continue;
        }
        cout << ans[y - 1][x] << "\n";
    }
}

int main() {
    ((void)0);
    ((void)0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
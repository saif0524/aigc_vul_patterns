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

const int MAXN = 205;

int n, k;
pair<int, int> seg[MAXN];
vector<int> ans;

bool check(int mask) {
    vector<int> cnt(MAXN,0);
    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
            for (int j = seg[i].first; j <= seg[i].second; ++j) {
                cnt[j]++;
                if (cnt[j] > k) return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> seg[i].first >> seg[i].second;
    }

    int best_mask = (1 << n) - 1;
    int min_segments = n;

    for (int mask = 0; mask < (1 << n); ++mask) {
        if (__builtin_popcount(mask) < min_segments && check(mask)) {
            min_segments = __builtin_popcount(mask);
            best_mask = mask;
        }
    }

    cout << min_segments << "\n";
    for (int i = 0; i < n; ++i) {
        if (!(best_mask & (1 << i))) {
            ans.push_back(i + 1);
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if (i < ans.size() - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}
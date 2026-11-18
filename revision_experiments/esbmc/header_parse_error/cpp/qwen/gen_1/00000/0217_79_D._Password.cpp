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

int main() {
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> x(k);
    for(int &i : x) cin >> i;
    vector<int> a(l);
    for(int &i : a) cin >> i;

    vector<int> target(n+1, 0);
    for(int i : x) target[i] = 1;

    int ans = INT_MAX;
    auto valid = [&](const vector<int> &state) -> bool {
        for(int i = 1; i <= n; ++i) {
            if(state[i] != target[i]) return false;
        }
        return true;
    };

    vector<int> state(n+1, 0);
    auto flip = [&](int start, int size) -> void {
        for(int i = start; i < start + size; ++i) {
            if(i > n) break;
            state[i] ^= 1;
        }
    };

    function<void(int, int)> backtrack = [&](int pos, int moves) -> void {
        if(pos > n) {
            if(valid(state)) {
                ans = min(ans, moves);
            }
            return;
        }
        if(moves >= ans) return;
        backtrack(pos + 1, moves);
        for(int j = 0; j < l; ++j) {
            if(pos + a[j] - 1 > n) continue;
            flip(pos, a[j]);
            backtrack(pos + a[j], moves + 1);
            flip(pos, a[j]);
        }
    };

    backtrack(1, 0);
    if(ans == INT_MAX) {
        cout << -1;
    } else {
        cout << ans;
    }
}
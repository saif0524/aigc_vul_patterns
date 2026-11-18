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

int n;
vector<int> dists;
vector<int> current;
vector<vector<int>> results;

bool check() {
    for (int i = 0; i < n; ++i) {
        set<int> s;
        for (int j = i + 1; j < n; ++j) {
            int sum = 0;
            for (int k = i; k < j; ++k) {
                sum += current[k - i];
            }
            s.insert(sum);
        }
        if (s.size() != (n - 1 - i)) return false;
    }
    return true;
}

void backtrack(int idx) {
    if (idx == n - 1) {
        if (check()) {
            results.push_back(current);
        }
        return;
    }
    set<int> used;
    for (int i = 0; i < dists.size(); ++i) {
        if (used.find(dists[i]) != used.end()) continue;
        used.insert(dists[i]);
        current[idx] = dists[i];
        backtrack(idx + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        if (n == 0) break;
        dists.clear();
        results.clear();
        current.assign(n - 1, 0);
        for (int i = 0; i < n * (n - 1) / 2; ++i) {
            int x;
            cin >> x;
            dists.push_back(x);
        }
        backtrack(0);
        sort(results.begin(), results.end());
        for (const auto& res : results) {
            for (int i = 0; i < res.size(); ++i) {
                if (i > 0) cout << ' ';
                cout << res[i];
            }
            cout << '\n';
        }
        cout << "-----\n";
    }
    return 0;
}
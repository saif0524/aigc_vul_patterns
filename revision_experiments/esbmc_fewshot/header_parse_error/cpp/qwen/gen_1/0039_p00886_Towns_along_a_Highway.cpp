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

vector<int> dists;
int n;
vector<vector<int>> results;

bool check(vector<int>& path) {
    vector<bool> used(n * (n - 1) / 2, false);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int d = abs(path[j] - path[i]);
            auto it = lower_bound(dists.begin(), dists.end(), d);
            if (it == dists.end() || *it != d || used[it - dists.begin()])
                return false;
            used[it - dists.begin()] = true;
        }
    }
    return true;
}

void backtrack(vector<int>& path) {
    if (path.size() == n) {
        if (check(path))
            results.push_back(path);
        return;
    }
    for (int i = 1; i <= 400; ++i) {
        if (find(path.begin(), path.end(), i) != path.end())
            continue;
        path.push_back(i);
        backtrack(path);
        path.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n && n) {
        dists.resize(n * (n - 1) / 2);
        for (auto& d : dists)
            cin >> d;
        sort(dists.begin(), dists.end());
        reverse(dists.begin(), dists.end());
        results.clear();
        vector<int> path;
        path.push_back(0);
        backtrack(path);
        sort(results.begin(), results.end());
        for (const auto& res : results) {
            for (int i = 1; i < n; ++i)
                cout << res[i] - res[i - 1] << (i < n - 1 ? ' ' : '\n');
        }
        cout << "-----\n";
    }
}
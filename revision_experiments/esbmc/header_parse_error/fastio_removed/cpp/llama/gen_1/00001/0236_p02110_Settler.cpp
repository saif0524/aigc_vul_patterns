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

int N, K;
vector<pair<int, int>> vacants;
vector<int> selected;

bool dist(pair<int, int> a, pair<int, int> b) {
    long long dx = a.first - b.first;
    long long dy = a.second - b.second;
    return dx * dx + dy * dy >= 4;
}

void backtrack(int idx, int cnt) {
    if (cnt == K) {
        for (int i : selected) {
            cout << i + 1 << '\n';
        }
        exit(0);
    }
    if (idx == N) return;
    bool ok = true;
    for (int i : selected) {
        if (!dist(vacants[i], vacants[idx])) {
            ok = false;
            break;
        }
    }
    if (ok) {
        selected.push_back(idx);
        backtrack(idx + 1, cnt + 1);
        selected.pop_back();
    }
    backtrack(idx + 1, cnt);
}

int main() {
    ((void)0);
    ((void)0);
    cin >> N >> K;
    vacants.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> vacants[i].first >> vacants[i].second;
    }
    backtrack(0, 0);
    cout << -1 << '\n';
    return 0;
}
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
    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }

    vector<int> cycle;
    vector<bool> used(N, false);

    for (int i = 0; i < N; i++) {
        if (used[i]) continue;
        cycle.clear();
        int now = i;
        while (!used[now]) {
            cycle.push_back(now);
            used[now] = true;
            now = P[now];
        }

        if (cycle.size() == 2 && cycle[0] + 1 == cycle[1] + 1) {
            cout << 1 << endl;
            return;
        }
    }

    vector<int> A(N, -1);
    for (int i = 0; i < N; i++) {
        A[P[i]] = i;
    }

    vector<int> pos;
    for (int i = 0; i < N; i++) {
        if (A[i] == i) {
            pos.push_back(i);
        }
    }

    sort(pos.begin(), pos.end());

    int x = pos.size();
    int ans = (x + 1) / 2;

    cout << ans << endl;
}

int main() {
    ((void)0);
    ((void)0);

    solve();

    return 0;
}
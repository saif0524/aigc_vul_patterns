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

typedef long long ll;

const int MAX_N = 100005;

int n, k;
int xi[MAX_N], yi[MAX_N];

void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &xi[i], &yi[i]);
    }

    vector<int> cnt(n + 5);

    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        st.insert(make_pair(xi[i], yi[i]));
    }

    for (int i = 0; i < n; i++) {
        for (int x = xi[i]; x - k + 1 <= xi[i]; x--) {
            for (int y = yi[i]; y - k + 1 <= yi[i]; y--) {
                int sum = 0;
                for (auto j : st) {
                    int x1 = j.first, y1 = j.second;
                    if (x1 >= x && x1 < x + k && y1 >= y && y1 < y + k) {
                        sum++;
                    }
                }
                if (sum <= n) {
                    cnt[sum]++;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", cnt[i] / 2);
    }
}

int main() {
    solve();
    return 0;
}
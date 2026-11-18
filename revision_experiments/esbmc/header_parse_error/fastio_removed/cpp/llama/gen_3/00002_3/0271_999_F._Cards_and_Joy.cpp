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
#define ll long long
using namespace std;

const int INF = 1e9 + 7;

int main() {
    ((void)0); ((void)0);

    int n, k;
    cin >> n >> k;

    vector<int> cards(k * n);
    for (int i = 0; i < k * n; ++i) {
        cin >> cards[i];
    }

    vector<int> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }

    vector<int> h(k);
    for (int i = 0; i < k; ++i) {
        cin >> h[i];
    }

    vector<vector<int>> adjacency(n, vector<int>());
    for (int i = 0; i < k * n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (cards[i] == f[j]) {
                adjacency[j].push_back(i);
            }
        }
    }

    vector<bool> visited(k * n, false);
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        sort(adjacency[i].begin(), adjacency[i].end(), [&visited](int a, int b) {
            return !visited[a] && visited[b];
        });
        for (int j = 0; j < k && j < adjacency[i].size(); ++j) {
            if (!visited[adjacency[i][j]]) {
                visited[adjacency[i][j]] = true;
                dp[i]++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += h[min(k - 1, dp[i])];
    }

    cout << ans << endl;

    return 0;
}
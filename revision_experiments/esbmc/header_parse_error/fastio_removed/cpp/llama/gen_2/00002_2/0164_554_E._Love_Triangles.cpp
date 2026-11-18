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
#define MOD 1000000007

using namespace std;

int main() {
    ((void)0);
    ((void)0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        graph[a][b] = graph[b][a] = c;
    }

    long long ans = 1;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != -1) {
                cnt++;
            }
        }
        if (cnt == 0) {
            ans = (ans * 2) % MOD;
        }
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] == 0) {
                int cnt = 0;
                for (int k = 0; k < n; k++) {
                    if (graph[i][k] == 1 && graph[j][k] == 1) {
                        cnt++;
                    }
                }
                if (cnt > 0) {
                    ok = false;
                }
            } else if (graph[i][j] == 1) {
                int cnt = 0;
                for (int k = 0; k < n; k++) {
                    if ((graph[i][k] == 0 && graph[j][k] == 0) || (graph[i][k] == 1 && graph[j][k] == 1)) {
                        cnt++;
                    }
                }
                if (cnt < n) {
                    ok = false;
                }
            }
        }
    }

    if (!ok) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
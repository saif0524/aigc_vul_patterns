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

const int MAX_N = 300005;

int n, k;
int s[MAX_N];
int ans[MAX_N];
int p[MAX_N];
int conf[MAX_N];
vector<int> a[MAX_N];

int get_confs(int idx) {
    if (conf[idx] != -1) return conf[idx];
    if (a[idx].size() == 0) return conf[idx] = 0;
    if (a[idx].size() == 1) return conf[idx] = (1 << (a[idx][0] - 1));
    else return conf[idx] = (1 << (a[idx][0] - 1)) | (1 << (a[idx][1] - 1));
}

void dfs(int idx, int ma) {
    if (ans[idx] <= ma) return;
    ans[idx] = ma;
    for (int i = 0; i < a[idx].size(); i++) {
        dfs(a[idx][i], ma + (p[a[idx][i]] == 0));
        dfs(a[idx][i], ma + (p[a[idx][i]] == 1));
    }
}

int main() {
    ((void)0);
    ((void)0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        s[i] = (c == '1');
    }
    for (int i = 1; i <= k; i++) {
        int c;
        cin >> c;
        a[i].resize(c);
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
        if (a[i].size() == 2) {
            p[a[i][0]] = (p[a[i][0]] | (1 << (i - 1)));
            p[a[i][1]] = (p[a[i][1]] | (1 << (i - 1)));
        }
    }
    memset(conf, -1, sizeof(conf));
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = 1; j <= k; j++) {
            if (a[j].size() == 1 && a[j][0] == i) {
                mx = max(mx, (int)(__builtin_popcount(get_confs(j)) % 2 == 0));
            }
            if (a[j].size() == 2 && (a[j][0] == i || a[j][1] == i)) {
                mx = max(mx, (int)(__builtin_popcount(get_confs(j)) % 2 == 0));
                mx = max(mx, (int)(__builtin_popcount((get_confs(j) ^ p[i])) % 2 == 0));
            }
        }
        ans[i] = k + 1;
        if (mx == 0 && !s[i]) dfs(i, 0);
        if (mx == 0 && s[i]) dfs(i, 1);
        if (mx == 1 && !s[i]) dfs(i, 1);
        if (mx == 1 && s[i]) dfs(i, 0);
        cout << ans[i] << '\n';
    }

    return 0;
}
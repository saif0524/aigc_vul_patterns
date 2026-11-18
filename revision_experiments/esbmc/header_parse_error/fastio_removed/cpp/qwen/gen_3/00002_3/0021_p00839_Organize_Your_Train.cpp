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

int x, y;
vector<pair<int, char>> connections[8];
string initial[4], target[4];
int dp[1 << 10][4][4];

int getMask(const string &s) {
    int mask = 0;
    for (char c : s) {
        mask |= (1 << (c - 'a'));
    }
    return mask;
}

bool canForm(int mask, const string &s) {
    int req = getMask(s);
    return (mask & req) == req;
}

int dfs(int mask, int a, int b) {
    if (mask == 0) return 0;
    if (dp[mask][a][b] != -1) return dp[mask][a][b];
    int res = 1e9;
    for (int i = 0; i < x; ++i) {
        if (canForm(mask, initial[i])) {
            int newMask = mask ^ getMask(initial[i]);
            res = min(res, 1 + dfs(newMask, i, b));
        }
        if (canForm(mask, target[i])) {
            int newMask = mask ^ getMask(target[i]);
            res = min(res, 1 + dfs(newMask, a, i));
        }
    }
    for (auto &[line, dir] : connections[a]) {
        if (dir == 'W') {
            for (int i = 0; i <= initial[line].size(); ++i) {
                string prefix = initial[line].substr(0, i);
                if (canForm(mask, prefix)) {
                    int newMask = mask ^ getMask(prefix);
                    int suffixMask = getMask(initial[line].substr(i));
                    for (auto &[targetLine, targetDir] : connections[line]) {
                        if (targetDir == 'E' && canForm(suffixMask, target[targetLine])) {
                            int finalMask = newMask ^ getMask(target[targetLine]);
                            res = min(res, 2 + dfs(finalMask, a, targetLine));
                        }
                    }
                }
            }
        } else {
            for (int i = 0; i <= initial[line].size(); ++i) {
                string suffix = initial[line].substr(i);
                if (canForm(mask, suffix)) {
                    int newMask = mask ^ getMask(suffix);
                    int prefixMask = getMask(initial[line].substr(0, i));
                    for (auto &[targetLine, targetDir] : connections[line]) {
                        if (targetDir == 'W' && canForm(prefixMask, target[targetLine])) {
                            int finalMask = newMask ^ getMask(target[targetLine]);
                            res = min(res, 2 + dfs(finalMask, a, targetLine));
                        }
                    }
                }
            }
        }
    }
    return dp[mask][a][b] = res;
}

int main() {
    ((void)0);
    ((void)0);
    while (cin >> x >> y) {
        if (x == 0 && y == 0) break;
        for (int i = 0; i < 8; ++i) connections[i].clear();
        for (int i = 0; i < (1 << 10); ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        for (int i = 0; i < y; ++i) {
            int p, q;
            char P, Q;
            cin >> p >> P >> q >> Q;
            connections[p].emplace_back(q, Q);
            connections[q].emplace_back(p, P);
        }
        for (int i = 0; i < x; ++i) cin >> initial[i];
        for (int i = 0; i < x; ++i) cin >> target[i];
        int fullMask = 0;
        for (int i = 0; i < x; ++i) {
            fullMask |= getMask(initial[i]);
        }
        cout << dfs(fullMask, 0, 0) << "\n";
    }
}
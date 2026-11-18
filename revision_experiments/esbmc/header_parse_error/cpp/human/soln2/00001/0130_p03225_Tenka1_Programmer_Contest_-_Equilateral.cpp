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

using ll = long long;

ll solve(const vector<string>& s, ll& hoge) {
    int H = s.size();
    int W = s.front().size();
    vector< vector<int> > sum(H + W - 1, vector<int>(H + 1, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            sum[i + j][i + 1] = (s[i][j] == '#');
        }
    }

    for (int i = 0; i < H + W - 1; i++) {
        for (int j = 1; j <= H; j++) {
            sum[i][j] += sum[i][j - 1];
        }
    }

    ll res = 0;
    for (int i = 0; i <= H + W - 2; i++) {
        for (int j = 0; j < H; j++) {
            int y1 = j;
            int x1 = i - j;
            if (x1 < 0) break;
            if (x1 >= W) continue;
            if (s[y1][x1] == '.') continue;
            for (int k = j + 1; k < H; k++) {
                int y2 = k;
                int x2 = i - k;
                if (x2 < 0) break;
                if (x2 >= W) continue;
                if (s[y2][x2] == '.') continue;
                int d = abs(y1 - y2) + abs(x1 - x2);
                if (d > i) continue;
                int tmp = sum[i - d][min(i - d, y1) + 1] - sum[i - d][max(i - d - x2, 0)];
                //cout << y1 << " " << x1 << ", " << y2 << " " << x2 << ": " << tmp << endl;
                res += tmp;

                if (x1 >= d) {
                    int y3 = y1, x3 = x1 - d;
                    //int d2 = abs(y2 - y3) + abs(x2 - x3);
                    if (s[y3][x3] == '#') {
                        hoge++;
                    }
                }

                if (y2 >= d) {
                    int y3 = y2 - d, x3 = x2;
                    if (s[y3][x3] == '#') {
                        hoge++;
                    }
                }
            }
        }
    }
    return res;
}

void rot(vector<string>& s) {
    int H = s.size();
    int W = s.front().size();
    vector<string> t(W, string(H, '.'));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            t[W-j-1][i] = s[i][j];
        }
    }
    s = move(t);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    vector<string> s(H);
    for (int i = 0; i < H; i++) {
        cin >> s[i];
    }

    ll hoge = 0, ans = 0;
    ans += solve(s, hoge);

    rot(s);
    ans += solve(s, hoge);

    rot(s);
    ans += solve(s, hoge);

    rot(s);
    ans += solve(s, hoge);
    hoge /= 2;
    ans -= hoge;
    cout << ans << endl;
    return 0;
}
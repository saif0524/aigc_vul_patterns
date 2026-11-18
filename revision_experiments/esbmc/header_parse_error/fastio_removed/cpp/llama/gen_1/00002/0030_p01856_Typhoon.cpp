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

const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int h, w;
int d[505][505];
int mark[505][505];

bool check(int x, int y) {
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i < 0 || j < 0 || i >= h || j >= w) continue;
            if (d[i][j] > 0 && mark[i][j] == 0) return false;
        }
    }
    return true;
}

void dfs(int x, int y, int buf[505][505]) {
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i < 0 || j < 0 || i >= h || j >= w) continue;
            if (buf[i][j] == 0 && d[i][j] != 0) {
                buf[i][j] = 1;
                dfs(i, j, buf);
            }
        }
    }
}

int main() {
    ((void)0);
    ((void)0);

    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> d[i][j];
        }
    }

    int sx, sy, tx, ty;
    for (int i = 1; i < h - 1; i++) {
        for (int j = 1; j < w - 1; j++) {
            int buf[505][505] = {};
            mark[i][j] = 1;
            dfs(i, j, mark);
            bool ok = true;
            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    if (d[k][l] == 3) ok = false;
                }
            }
            if (ok) {
                for (int k = 0; k < h; k++) {
                    for (int l = 0; l < w; l++) {
                        if (mark[k][l] == 1 && d[k][l] == 0) {
                            tx = k;
                            ty = l;
                            goto out;
                        }
                    }
                }
            }
            memset(mark, 0, sizeof mark);
        }
    }
out:
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (d[i][j] == 3) {
                sx = i;
                sy = j;
                break;
            }
        }
    }

    cout << sx + 1 << " " << sy + 1 << " " << tx + 1 << " " << ty + 1 << endl;

    return 0;
}
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

int main() {
    int kx, ky;
    cin >> kx >> ky;
    set<pair<int, int>> rooks;
    for (int i = 0; i < 666; ++i) {
        int x, y;
        cin >> x >> y;
        rooks.insert({x, y});
    }

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    
    int mx = -1, my = -1;
    while (true) {
        for (auto [dx, dy] : directions) {
            int nx = kx + dx, ny = ky + dy;
            if (nx >= 1 && nx <= 999 && ny >= 1 && ny <= 999 && rooks.find({nx, ny}) == rooks.end()) {
                mx = nx;
                my = ny;
                break;
            }
        }
        if (mx == -1) break;
        cout << mx << " " << my << endl;
        cout.flush();
        kx = mx;
        ky = my;
        mx = -1, my = -1;
        int rk, rx, ry;
        cin >> rk >> rx >> ry;
        if (rk == -1 && rx == -1 && ry == -1) break;
        rooks.erase({rx, ry});
    }
}
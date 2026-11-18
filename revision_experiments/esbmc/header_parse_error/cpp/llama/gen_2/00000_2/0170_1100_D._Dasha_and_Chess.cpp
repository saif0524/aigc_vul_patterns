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

const int maxn = 1005;

struct Point {
    int x, y;
};

Point king, rooks[666];

bool is_over() {
    for (int i = 0; i < 666; i++) {
        if (king.x == rooks[i].x || king.y == rooks[i].y) {
            return true;
        }
    }
    return false;
}

void move_king(int dx, int dy) {
    if (rooks[0].x == king.x + dx && rooks[0].y == king.y + dy) {
        return;
    }
    king.x += dx;
    king.y += dy;
    cout << king.x << " " << king.y << endl;
}

void read_rook_move() {
    int k, x, y;
    cin >> k >> x >> y;
    if (k == -1 && x == -1 && y == -1) {
        exit(0);
    }
    rooks[k - 1].x = x;
    rooks[k - 1].y = y;
}

int main() {
    int n = 666;
    cin >> king.x >> king.y;
    for (int i = 0; i < n; i++) {
        cin >> rooks[i].x >> rooks[i].y;
    }
    while (!is_over()) {
        if (king.x > 500) {
            if (king.y > 500) {
                move_king(0, -1);
            } else {
                move_king(0, 1);
            }
        } else {
            if (king.y > 500) {
                move_king(-1, 0);
            } else {
                move_king(1, 0);
            }
        }
        read_rook_move();
    }
    return 0;
}
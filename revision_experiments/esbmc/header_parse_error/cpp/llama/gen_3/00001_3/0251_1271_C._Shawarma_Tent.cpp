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

struct Student {
    int x, y;
    int dx, dy;

    Student(int _x, int _y, int sx, int sy) {
etti:
        x = _x; y = _y;
        dx = x - sx;
        dy = y - sy;
        if (dx < 0) dx = -dx;
        if (dy < 0) dy = -dy;
    }

    string toString() {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, sx, sy;
    cin >> n >> sx >> sy;
    vector<Student> students;
    map<int, int> up, down, left, right;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        students.emplace_back(x, y, sx, sy);
    }

    bool found = false;
    int best = 0, bestx, besty;
    for (int x = 0; x <= 1e9; x++) {
        int cnt = 0, oldcnt = 0;
        for (Student& s : students) {
            if (s.dx >= abs(x - sx) && s.dy >= abs(y - sy)) cnt++;
            if (abs(s.x - x) + abs(s.y - sy) == s.dx + s.dy) oldcnt++;
        }
        if (cnt > best) {
            found = true; best = cnt;
            bestx = x; besty = sy;
        }
    }
    for (int y = 0; y <= 1e9; y++) {
        int cnt = 0, oldcnt = 0;
        for (Student& s : students) {
            if (s.dx >= abs(x - sx) && s.dy >= abs(y - sy)) cnt++;
            if (abs(s.x - sx) + abs(s.y - y) == s.dx + s.dy) oldcnt++;
        }
        if (cnt > best) {
            found = true; best = cnt;
            bestx = sx; besty = y;
        }
    }

    if (found) {
        cout << best << '\n';
        cout << bestx << ' ' << besty << '\n';
    }
    else {
        cout << 0 << '\n';
        cout << "0 0" << '\n';
    }

    return 0;
}
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

const double EPS = 1e-6;

struct Point {
    double x, y;
};

struct Block {
    double x1, y1, x2, y2, h;
};

bool isOnLine(const Point& p, const Point& a, const Point& b) {
    if (abs(a.x - b.x) < EPS) {
        return abs(p.x - a.x) < EPS;
    } else {
        return abs(p.y - a.y) < EPS;
    }
}

double dist(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double lineDist(const Point& p, const Point& a, const Point& b) {
    return abs((b.x - a.x) * (a.y - p.y) - (a.x - p.x) * (b.y - a.y)) / dist(a, b);
}

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;
        Point start, end;
        cin >> start.x >> start.y >> end.x >> end.y;
        vector<Block> blocks(N);
        for (int i = 0; i < N; i++) {
            cin >> blocks[i].x1 >> blocks[i].y1 >> blocks[i].x2 >> blocks[i].y2 >> blocks[i].h;
        }

        double low = 0, high = 1001;
        while (high - low > EPS) {
            double mid = (low + high) / 2;
            bool valid = true;
            for (const Block& block : blocks) {
                Point p1 = {block.x1, block.y1}, p2 = {block.x2, block.y2};
                if (isOnLine(p1, start, end) || isOnLine(p2, start, end)) {
                    valid = false;
                    break;
                }
                if (lineDist(p1, start, end) < mid + EPS && lineDist(p2, start, end) < mid + EPS) {
                    valid = false;
                    break;
                }
                if (lineDist(p1, start, end) < mid + EPS && block.h > mid) {
                    valid = false;
                    break;
                }
                if (lineDist(p2, start, end) < mid + EPS && block.h > mid) {
                    valid = false;
                    break;
                }
                if (dist(p1, start) < mid + EPS && block.h > mid) {
                    valid = false;
                    break;
                }
                if (dist(p2, start) < mid + EPS && block.h > mid) {
                    valid = false;
                    break;
                }
                if (dist(p1, end) < mid + EPS && block.h > mid) {
                    valid = false;
                    break;
                }
                if (dist(p2, end) < mid + EPS && block.h > mid) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                low = mid;
            } else {
                high = mid;
            }
        }
        printf("%.9f\n", low);
    }
    return 0;
}
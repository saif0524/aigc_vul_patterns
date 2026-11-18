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

const int MAX_N = 1005;
const int MOVES[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

struct Segment {
    int row, start, end;
};

bool isValid(int x, int y, const vector<Segment>& segments) {
    for (const auto& segment : segments) {
        if (segment.row == x && segment.start <= y && y <= segment.end) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;

    int n;
    cin >> n;

    vector<Segment> segments(n);
    for (auto& segment : segments) {
        cin >> segment.row >> segment.start >> segment.end;
    }

    deque<pair<int, int>> queue;
    queue.push_back({x0, y0});
    vector<vector<int>> distance(MAX_N, vector<int>(MAX_N, -1));
    distance[x0][y0] = 0;

    while (!queue.empty()) {
        auto [x, y] = queue.front();
        queue.pop_front();

        for (const auto& move : MOVES) {
            int newX = x + move[0];
            int newY = y + move[1];

            if (newX < 1 || newX > 100 || newY < 1 || newY > 100) {
                continue;
            }

            if (!isValid(newX, newY, segments)) {
                continue;
            }

            if (distance[newX][newY] != -1) {
                continue;
            }

            distance[newX][newY] = distance[x][y] + 1;
            queue.push_back({newX, newY});
        }
    }

    cout << distance[x1][y1] << endl;

    return 0;
}
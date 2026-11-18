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

struct State {
    int x, y, apples;
    State(int x, int y, int apples) : x(x), y(y), apples(apples) {}
};

bool operator<(const State &a, const State &b) {
    return make_tuple(a.x, a.y, a.apples) < make_tuple(b.x, b.y, b.apples);
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> grid(H);
    int sx, sy, ex, ey;
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == 's') sx = i, sy = j;
            if (grid[i][j] == 'e') ex = i, ey = j;
        }
    }

    priority_queue<pair<int, State>, vector<pair<int, State>>, greater<pair<int, State>>> pq;
    unordered_set<string> visited;
    pq.emplace(0, State(sx, sy, 0));
    visited.insert(to_string(sx) + "," + to_string(sy) + "," + to_string(0));

    while (!pq.empty()) {
        auto [cost, st] = pq.top();
        pq.pop();
        int x = st.x, y = st.y, apples = st.apples;

        if (x == ex && y == ey && apples >= K) {
            cout << cost << "\n";
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W || grid[nx][ny] == '#') continue;
            int napples = apples;
            if (grid[nx][ny] == 'a') napples = min(20, napples + 1);
            string state = to_string(nx) + "," + to_string(ny) + "," + to_string(napples);
            if (!visited.count(state)) {
                visited.insert(state);
                pq.emplace(cost + 1, State(nx, ny, napples));
            }
        }
    }

    cout << "-1\n";
    return 0;
}
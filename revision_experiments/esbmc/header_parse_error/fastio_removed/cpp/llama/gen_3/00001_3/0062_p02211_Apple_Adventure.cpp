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

const int INF = 1e9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct State {
    int x, y, apples, dist;
    State(int x, int y, int apples, int dist) : x(x), y(y), apples(apples), dist(dist) {}
};

int main() {
    ((void)0);
    ((void)0);

    int H, W, K;
    cin >> H >> W >> K;

    vector<string> grid(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    int sx, sy, ex, ey;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 's') {
                sx = i;
                sy = j;
            } else if (grid[i][j] == 'e') {
                ex = i;
                ey = j;
            }
        }
    }

    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(1 << 20, INF)));
    queue<State> q;
    q.push(State(sx, sy, 0, 0));
    dist[sx][sy][0] = 0;

    while (!q.empty()) {
        State state = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = state.x + dx[i];
            int ny = state.y + dy[i];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W || grid[nx][ny] == '#') {
                continue;
            }

            int napples = state.apples;
            if (grid[nx][ny] == 'a') {
                napples++;
            }

            if (dist[nx][ny][napples] > state.dist + 1) {
                dist[nx][ny][napples] = state.dist + 1;
                q.push(State(nx, ny, napples, state.dist + 1));
            }
        }
    }

    int ans = INF;
    for (int i = K; i < (1 << 20); i++) {
        if (dist[ex][ey][i] < ans) {
            ans = dist[ex][ey][i];
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
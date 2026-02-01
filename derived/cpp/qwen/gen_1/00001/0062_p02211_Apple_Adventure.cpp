#include <bits/stdc++.h>
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
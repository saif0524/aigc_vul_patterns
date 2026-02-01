#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Point {
    int x, y;
};

struct State {
    Point p;
    int apples;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, K;
    cin >> H >> W >> K;

    vector<vector<char>> grid(H, vector<char>(W));
    vector<Point> apples;
    Point start, end;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 's') {
                start = {i, j};
            } else if (grid[i][j] == 'e') {
                end = {i, j};
            } else if (grid[i][j] == 'a') {
                apples.push_back({i, j});
            }
        }
    }

    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};

    queue<State> q;
    q.push({start, 0});

    vector<vector<vector<bool>>> visited(H, vector<vector<bool>>(W, vector<bool>(1 << apples.size())));

    int ans = numeric_limits<int>::max();

    while (!q.empty()) {
        State state = q.front();
        q.pop();

        if (state.p.x == end.x && state.p.y == end.y && __builtin_popcount(state.apples) >= K) {
            ans = min(ans, state.apples);
        }

        for (int i = 0; i < 4; i++) {
            int nx = state.p.x + dx[i];
            int ny = state.p.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= H || ny >= W || grid[nx][ny] == '#') {
                continue;
            }

            int na = state.apples;
            for (int j = 0; j < apples.size(); j++) {
                if (nx == apples[j].x && ny == apples[j].y && !(na & (1 << j))) {
                    na |= (1 << j);
                    break;
                }
            }

            if (!visited[nx][ny][na]) {
                visited[nx][ny][na] = true;
                q.push({{nx, ny}, na + 1});
            }
        }
    }

    if (ans == numeric_limits<int>::max()) {
        cout << -1 << endl;
    } else {
        cout << ans - 1 << endl;
    }

    return 0;
}
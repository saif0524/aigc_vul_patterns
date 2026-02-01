#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

struct State {
    int x[3], y[3], cost;
    State(int x0, int y0, int x1, int y1, int x2, int y2, int c) : cost(c) {
        x[0] = x0, y[0] = y0, x[1] = x1, y[1] = y1, x[2] = x2, y[2] = y2;
    }
    bool operator<(const State& other) const {
        return cost > other.cost;
    }
};

int bfs(vector<string>& grid, int w, int h, vector<int>& start_x, vector<int>& start_y, vector<int>& end_x, vector<int>& end_y) {
    using State = struct State;
    int n = start_x.size();
    priority_queue<State> pq;
    unordered_set<string> visited;
    string start_state = "";
    for (int i = 0; i < n; ++i) {
        start_state += start_x[i] + '0';
        start_state += start_y[i] + '0';
    }
    pq.emplace(start_x[0], start_y[0], start_x[1], start_y[1], start_x[2], start_y[2], 0);
    visited.insert(start_state);
    while (!pq.empty()) {
        auto [x0, y0, x1, y1, x2, y2, cost] = pq.top();
        pq.pop();
        int x[3] = {x0, x1, x2};
        int y[3] = {y0, y1, y2};
        bool goal = true;
        for (int i = 0; i < n; ++i) {
            if (x[i] != end_x[i] || y[i] != end_y[i]) goal = false;
        }
        if (goal) return cost;
        for (int i = 0; i < (1 << (2 * n)); ++i) {
            int new_x[3], new_y[3];
            bool valid = true;
            for (int j = 0; j < n; ++j) {
                int dir = (i >> (2 * j)) & 3;
                new_x[j] = x[j] + dx[dir];
                new_y[j] = y[j] + dy[dir];
                if (grid[new_x[j]][new_y[j]] == '#') {
                    valid = false;
                    break;
                }
            }
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (j != k && new_x[j] == new_x[k] && new_y[j] == new_y[k]) {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid) {
                string new_state = "";
                for (int j = 0; j < n; ++j) {
                    new_state += new_x[j] + '0';
                    new_state += new_y[j] + '0';
                }
                if (visited.find(new_state) == visited.end()) {
                    visited.insert(new_state);
                    if (n == 1) {
                        pq.emplace(new_x[0], new_y[0], x1, y1, x2, y2, cost + 1);
                    } else if (n == 2) {
                        pq.emplace(new_x[0], new_y[0], new_x[1], new_y[1], x2, y2, cost + 1);
                    } else {
                        pq.emplace(new_x[0], new_y[0], new_x[1], new_y[1], new_x[2], new_y[2], cost + 1);
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        int w, h, n;
        cin >> w >> h >> n;
        if (w == 0 && h == 0 && n == 0) break;
        vector<string> grid(h);
        for (int i = 0; i < h; ++i) {
            cin >> grid[i];
        }
        vector<int> start_x(n), start_y(n), end_x(n), end_y(n);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] >= 'a' && grid[i][j] <= 'c') {
                    start_x[grid[i][j] - 'a'] = i;
                    start_y[grid[i][j] - 'a'] = j;
                }
                if (grid[i][j] >= 'A' && grid[i][j] <= 'C') {
                    end_x[grid[i][j] - 'A'] = i;
                    end_y[grid[i][j] - 'A'] = j;
                }
            }
        }
        cout << bfs(grid, w, h, start_x, start_y, end_x, end_y) << "\n";
    }
}
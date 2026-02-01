#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;
};

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

struct State {
    vector<Node> positions;
    string code() const {
        string s;
        for (auto &node : positions) {
            s += to_string(node.x);
            s += to_string(node.y);
        }
        return s;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int w, h, n;
    while (cin >> w >> h >> n) {
        if (w == 0 && h == 0 && n == 0) break;
        vector<string> map(h);
        for (auto &row : map) {
            cin >> row;
        }

        State start;
        vector<Node> targets(n);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] >= 'a' && map[i][j] <= 'z') {
                    start.positions.push_back({i, j});
                } else if (map[i][j] >= 'A' && map[i][j] <= 'Z') {
                    targets[map[i][j] - 'A'].x = i;
                    targets[map[i][j] - 'A'].y = j;
                }
            }
        }

        queue<pair<State, int>> q;
        q.push({start, 0});
        unordered_set<string> visited;
        visited.insert(start.code());

        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            if (current.first.positions == targets) {
                cout << current.second << "\n";
                break;
            }

            for (int i = 0; i < (1 << n); i++) {
                State nextState = current.first;
                bool valid = true;
                for (int j = 0; j < n; j++) {
                    if (i & (1 << j)) {
                        for (int k = 0; k < 4; k++) {
                            int x = nextState.positions[j].x + dx[k];
                            int y = nextState.positions[j].y + dy[k];
                            if (map[x][y] != '#' && !(i & (1 << j)) != (nextState.positions[j].x == x && nextState.positions[j].y == y)) {
                                nextState.positions[j].x = x;
                                nextState.positions[j].y = y;
                                break;
                            }
                        }
                        if (nextState.positions[j].x == start.positions[j].x && nextState.positions[j].y == start.positions[j].y) {
                            valid = false;
                            break;
                        }
                    }
                }

                if (valid && visited.find(nextState.code()) == visited.end()) {
                    visited.insert(nextState.code());
                    q.push({nextState, current.second + 1});
                }
            }
        }
    }
    return 0;
}
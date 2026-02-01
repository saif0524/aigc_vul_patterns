#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

struct State {
    vector<pair<int, int>> ghosts;
    int step;
    State(vector<pair<int, int>> ghosts, int step) : ghosts(ghosts), step(step) {}
};

int w, h, n;
vector<string> map;
vector<pair<int, int>> goal;
vector<pair<int, int>> start;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isValid(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w && map[x][y] != '#';
}

int getDist(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> w >> h >> n) {
        if (w == 0 && h == 0 && n == 0) break;

        map.resize(h);
        goal.resize(n);
        start.resize(n);

        for (int i = 0; i < h; i++) {
            cin >> map[i];
            for (int j = 0; j < w; j++) {
                if (map[i][j] >= 'a' && map[i][j] <= 'z') {
                    start[map[i][j] - 'a'] = {i, j};
                } else if (map[i][j] >= 'A' && map[i][j] <= 'Z') {
                    goal[map[i][j] - 'A'] = {i, j};
                }
            }
        }

        queue<State> q;
        q.push(State(start, 0));

        vector<vector<pair<int, int>>> visited(n);
        for (int i = 0; i < n; i++) {
            visited[i].push_back(start[i]);
        }

        while (!q.empty()) {
            State state = q.front();
            q.pop();

            if (state.ghosts == goal) {
                cout << state.step << endl;
                break;
            }

            for (int i = 0; i < n; i++) {
                for (int k = 0; k < 4; k++) {
                    int nx = state.ghosts[i].first + dx[k];
                    int ny = state.ghosts[i].second + dy[k];

                    if (isValid(nx, ny)) {
                        vector<pair<int, int>> next_state = state.ghosts;
                        next_state[i] = {nx, ny};

                        bool valid = true;
                        for (int j = 0; j < n; j++) {
                            if (i != j && next_state[i] == next_state[j]) {
                                valid = false;
                                break;
                            }
                        }

                        if (valid) {
                            bool visitedFlag = false;
                            for (int j = 0; j < visited[i].size(); j++) {
                                if (visited[i][j] == next_state[i]) {
                                    visitedFlag = true;
                                    break;
                                }
                            }

                            if (!visitedFlag) {
                                visited[i].push_back(next_state[i]);
                                q.push(State(next_state, state.step + 1));
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
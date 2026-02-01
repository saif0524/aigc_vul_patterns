#include <bits/stdc++.h>
using namespace std;

int w, h, n;
char grid[20][20];
vector<pair<int, int>> ghosts, targets;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w && grid[x][y] != '#';
}

int bfs(vector<pair<int, int>> start, vector<pair<int, int>> end) {
    queue<pair<vector<pair<int, int>>, int>> q;
    q.push({start, 0});
    set<vector<pair<int, int>>> visited;
    visited.insert(start);
    
    while (!q.empty()) {
        auto current = q.front(); q.pop();
        vector<pair<int, int>> pos = current.first;
        int steps = current.second;
        
        if (pos == end) return steps;
        
        int m = pos.size();
        for (int i = 0; i < m; i++) {
            int x = pos[i].first, y = pos[i].second;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (valid(nx, ny)) {
                    vector<pair<int, int>> new_pos = pos;
                    new_pos[i] = {nx, ny};
                    bool valid_move = true;
                    for (int j = 0; j < m; j++) {
                        for (int k = j + 1; k < m; k++) {
                            if (new_pos[j] == new_pos[k]) {
                                valid_move = false;
                                break;
                            }
                        }
                        if (!valid_move) break;
                    }
                    if (valid_move && visited.find(new_pos) == visited.end()) {
                        visited.insert(new_pos);
                        q.push({new_pos, steps + 1});
                    }
                }
            }
            vector<pair<int, int>> stay_pos = pos;
            stay_pos[i] = {x, y};
            bool valid_move = true;
            for (int j = 0; j < m; j++) {
                for (int k = j + 1; k < m; k++) {
                    if (stay_pos[j] == stay_pos[k]) {
                        valid_move = false;
                        break;
                    }
                }
                if (!valid_move) break;
            }
            if (valid_move && visited.find(stay_pos) == visited.end()) {
                visited.insert(stay_pos);
                q.push({stay_pos, steps + 1});
            }
        }
    }
    return -1;
}

int main() {
    while (true) {
        cin >> w >> h >> n;
        if (w == 0 && h == 0 && n == 0) break;
        ghosts.clear();
        targets.clear();
        for (int i = 0; i < h; i++) {
            cin >> grid[i];
            for (int j = 0; j < w; j++) {
                if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    ghosts.push_back({i, j});
                }
                if (grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
                    targets.push_back({i, j});
                }
            }
        }
        sort(ghosts.begin(), ghosts.end());
        sort(targets.begin(), targets.end());
        cout << bfs(ghosts, targets) << "\n";
    }
    return 0;
}
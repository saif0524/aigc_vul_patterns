#include <bits/stdc++.h>
using namespace std;

int h, w, n, r;
char grid[9][9];
int treasure[128];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int visited[9][9][1 << 10];

bool isValid(int x, int y) {
    return (x >= 0 && x < h && y >= 0 && y < w && grid[x][y] != '#');
}

int bfs(int startX, int startY) {
    queue<tuple<int, int, int, int>> q; // x, y, mask, cost
    q.emplace(startX, startY, 0, 0);
    visited[startX][startY][0] = 1;
    int maxMoney = 0;

    while (!q.empty()) {
        auto [x, y, mask, cost] = q.front();
        q.pop();

        if (isalpha(grid[x][y])) {
            int val = treasure[grid[x][y]];
            if (!(mask & (1 << (grid[x][y] - 'a')))) {
                mask |= (1 << (grid[x][y] - 'a'));
                maxMoney = max(maxMoney, cost + val);
            }
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny)) {
                if (grid[nx][ny] == '*') {
                    int newCost = cost + r;
                    if (visited[nx][ny][mask] == 0 || visited[nx][ny][mask] > newCost) {
                        visited[nx][ny][mask] = newCost;
                        q.emplace(nx, ny, mask, newCost);
                    }
                } else {
                    if (visited[nx][ny][mask] == 0) {
                        visited[nx][ny][mask] = cost;
                        q.emplace(nx, ny, mask, cost);
                    }
                }
            }
        }
    }

    return maxMoney;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w >> n >> r;
    int startX, startY;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> grid[i][j];
            if(grid[i][j] == '@'){
                startX = i;
                startY = j;
            }
        }
    }
    for(int i = 0; i < n; i++){
        char type; int value;
        cin >> type >> value;
        treasure[type] = value;
    }
    cout << bfs(startX, startY) << "\n";
}
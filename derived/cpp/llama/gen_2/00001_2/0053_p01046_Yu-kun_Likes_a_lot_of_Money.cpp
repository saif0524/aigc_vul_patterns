#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int h, w, n, r;
vector<string> map;
vector<Point> treasure;
unordered_map<char, int> value;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int x, int y, vector<vector<bool>>& visited) {
    queue<pair<Point, int>> q;
    q.push({{x, y}, 0});
    int maxVal = 0;
    while (!q.empty()) {
        int curX = q.front().first.x;
        int curY = q.front().first.y;
        int curCost = q.front().second;
        maxVal = max(maxVal, curCost);
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newX = curX + dx[i];
            int newY = curY + dy[i];
            if (newX < 0 || newX >= h || newY < 0 || newY >= w || visited[newX][newY]) continue;
            visited[newX][newY] = true;
            if (map[newX][newY] == '#') continue;
            if (map[newX][newY] == '*') {
                q.push({{newX, newY}, curCost - r});
            } else if (map[newX][newY] >= '0' && map[newX][newY] <= '9' || map[newX][newY] >= 'a' && map[newX][newY] <= 'z' || map[newX][newY] >= 'A' && map[newX][newY] <= 'Z') {
                q.push({{newX, newY}, curCost + value[map[newX][newY]]});
            } else {
                q.push({{newX, newY}, curCost});
            }
        }
    }
    return maxVal;
}

int main() {
    cin >> h >> w >> n >> r;
    map.resize(h);
    for (int i = 0; i < h; i++) {
        cin >> map[i];
    }
    int x, y;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (map[i][j] == '@') {
                x = i;
                y = j;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        char c;
        int v;
        cin >> c >> v;
        value[c] = v;
    }
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    visited[x][y] = true;
    int result = bfs(x, y, visited);
    cout << max(0, result) << endl;
    return 0;
}
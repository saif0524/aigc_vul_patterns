#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;

    int n;
    cin >> n;

    vector<vector<bool>> allowed(109, vector<bool>(109, false));
    for (int i = 0; i < n; ++i) {
        int r, a, b;
        cin >> r >> a >> b;
        for (int j = a; j <= b; ++j) {
            allowed[r][j] = true;
        }
    }

    if (!allowed[x0][y0] || !allowed[x1][y1]) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> dist(109, vector<int>(109, -1));
    queue<pair<int, int>> q;

    dist[x0][y0] = 0;
    q.push({x0, y0});

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= 109 && ny >= 1 && ny <= 109 && allowed[nx][ny] && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << dist[x1][y1] << endl;

    return 0;
}
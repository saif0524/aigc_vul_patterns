#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    string path;
    set<char> types;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int sx, sy, tx, ty;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (grid[i][j] == 'T') {
                tx = i;
                ty = j;
            }
        }
    }

    queue<Point> q;
    q.push({sx, sy, "", {}});

    set<pair<string, set<char>>> visited;

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        if (p.x == tx && p.y == ty) {
            cout << p.path << endl;
            return 0;
        }

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) + abs(dy)!= 1) continue;

                int nx = p.x + dx;
                int ny = p.y + dy;

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                char c = grid[nx][ny];
                if (c == 'S' || c == 'T') c = '\0';

                set<char> newTypes = p.types;
                if (c!= '\0') newTypes.insert(c);

                if (newTypes.size() > k) continue;

                string newPath = p.path;
                if (c!= '\0') newPath += c;

                pair<string, set<char>> key = {newPath, newTypes};
                if (visited.find(key)!= visited.end()) continue;

                visited.insert(key);
                q.push({nx, ny, newPath, newTypes});
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
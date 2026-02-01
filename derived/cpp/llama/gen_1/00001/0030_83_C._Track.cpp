#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int x, y;
    string path;
    set<char> types;
};

int n, m, k;
vector<string> grid;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

string bfs() {
    queue<Node> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                q.push({i, j, "", {}});
            }
        }
    }

    while (!q.empty()) {
        Node node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (grid[nx][ny] == 'T') {
                    return node.path;
                }

                char nextChar = grid[nx][ny];
                if (nextChar != 'S' && nextChar != 'T' && node.types.find(nextChar) == node.types.end() && node.types.size() < k) {
                    set<char> newTypes = node.types;
                    newTypes.insert(nextChar);
                    q.push({nx, ny, node.path + nextChar, newTypes});
                } else if (nextChar != 'S' && nextChar != 'T' && node.types.find(nextChar) != node.types.end()) {
                    q.push({nx, ny, node.path + nextChar, node.types});
                }
            }
        }
    }

    return "-1";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    string res = bfs();
    if (res == "-1") {
        cout << res << endl;
    } else {
        sort(res.begin(), res.end());
        cout << res << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> field(n);
    for (int i = 0; i < n; ++i) {
        cin >> field[i];
    }

    vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    string dirs = "LRUD";

    set<pair<int, int>> used;
    int mx = 0;
    int cnt = 0;

    int dx[128];
    dx['L'] = 0;
    dx['R'] = 1;
    dx['U'] = 2;
    dx['D'] = 3;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field[i][j] == '.') continue;

            if (used.find({i, j}) != used.end()) continue;

            int x = i;
            int y = j;
            int len = 1;
            used.insert({x, y});

            while (true) {
                int nx = x + directions[dx[field[x][y]]][0];
                int ny = y + directions[dx[field[x][y]]][1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || field[nx][ny] == '.') break;

                if (used.find({nx, ny}) != used.end()) break;

                used.insert({nx, ny});
                len++;
                x = nx;
                y = ny;
            }

            if (len > mx) {
                mx = len;
                cnt = 1;
            } else if (len == mx) {
                cnt++;
            }

            used.clear();
        }
    }

    cout << mx << " " << cnt << endl;

    return 0;
}
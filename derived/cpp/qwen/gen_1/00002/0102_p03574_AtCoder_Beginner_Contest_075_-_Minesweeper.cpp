#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (auto &s : grid) cin >> s;

    vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},         {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == '.') {
                int bomb_count = 0;
                for (auto [di, dj] : directions) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < H && nj >= 0 && nj < W && grid[ni][nj] == '#') {
                        ++bomb_count;
                    }
                }
                grid[i][j] = bomb_count + '0';
            }
        }
    }

    for (const auto &s : grid) {
        cout << s << "\n";
    }

    return 0;
}
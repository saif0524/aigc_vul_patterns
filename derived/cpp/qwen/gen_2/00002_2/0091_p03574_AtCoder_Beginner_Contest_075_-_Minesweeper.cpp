#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
    }

    vector<string> result(h);
    for (int i = 0; i < h; ++i) {
        result[i] = "";
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '.') {
                int bomb_count = 0;
                for (int x = max(0, i - 1); x <= min(h - 1, i + 1); ++x) {
                    for (int y = max(0, j - 1); y <= min(w - 1, j + 1); ++y) {
                        if (x == i && y == j) continue;
                        if (grid[x][y] == '#') {
                            bomb_count++;
                        }
                    }
                }
                result[i] += to_string(bomb_count);
            } else {
                result[i] += '#';
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
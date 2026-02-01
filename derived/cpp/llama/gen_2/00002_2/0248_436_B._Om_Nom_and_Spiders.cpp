#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> field(n);
    for (int i = 0; i < n; i++) {
        cin >> field[i];
    }

    vector<vector<int>> spiders(n, vector<int>(m, 0));
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == 'L') {
                spiders[i][j]++;
            } else if (field[i][j] == 'R') {
                spiders[i][j]++;
            } else if (field[i][j] == 'U') {
                spiders[i][j]++;
            } else if (field[i][j] == 'D') {
                spiders[i][j]++;
            }
        }
    }

    vector<int> result(m, 0);
    for (int i = 0; i < m; i++) {
        int x = i;
        int y = 0;
        int time = 0;
        while (y < n - 1) {
            time++;
            y++;
            if (x > 0 && field[y][x - 1] == 'L') {
                result[i]++;
            }
            if (x < m - 1 && field[y][x + 1] == 'R') {
                result[i]++;
            }
            if (y > 0 && field[y - 1][x] == 'U') {
                result[i]++;
            }
            if (y < n - 1 && field[y + 1][x] == 'D') {
                result[i]++;
            }
            if (field[y][x] == 'L') {
                x--;
            } else if (field[y][x] == 'R') {
                x++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int DIR[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const char DIR_CHAR[] = {'R', 'L', 'D', 'U'};

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    vector<vector<bool>> grid(n, vector<bool>(m, false));
    vector<vector<int>> moves(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            scanf(" %c", &c);
            if (c != '.') {
                for (int d = 0; d < 4; ++d) {
                    if (DIR_CHAR[d] == c) {
                        moves[i][j] = d;
                        break;
                    }
                }
                grid[i][j] = true;
            }
        }
    }

    vector<vector<int>> spider_counts(n, vector<int>(m, 0));

    for (int t = 0; t < n * 2; ++t) {
        vector<vector<int>> new_grid(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    new_grid[max(0, min(n - 1, i + DIR[moves[i][j]][0]))][max(0, min(m - 1, j + DIR[moves[i][j]][1]))]++;
                    spider_counts[max(0, min(n - 1, i + DIR[moves[i][j]][0]))][max(0, min(m - 1, j + DIR[moves[i][j]][1]))]++;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                grid[i][j] = new_grid[i][j] > 0;
                moves[i][j] = new_grid[i][j] > 0 ? moves[i][j] : 0;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        printf("%d", spider_counts[0][i]);
        if (i < m - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <set>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> grid(n, std::vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> grid[i][j];
        }
    }

    std::vector<std::vector<bool>> crossed(n, std::vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i + 1; k < n; k++) {
                if (grid[i][j] == grid[k][j]) {
                    crossed[i][j] = true;
                    crossed[k][j] = true;
                }
            }
            for (int k = j + 1; k < m; k++) {
                if (grid[i][j] == grid[i][k]) {
                    crossed[i][j] = true;
                    crossed[i][k] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!crossed[i][j]) {
                std::cout << grid[i][j];
            }
        }
    }

    return 0;
}
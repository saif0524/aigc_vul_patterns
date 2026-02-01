#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int MAX_N = 205;
const int MAX_M = 205;

std::vector<std::vector<char>> grid(MAX_N, std::vector<char>(MAX_M));
std::vector<std::pair<int, int>> moves(10);

bool dfs(int x, int y, const std::string& target, int idx) {
    if (x < 0 || x >= MAX_N || y < 0 || y >= MAX_M) {
        return false;
    }

    if (idx == target.size()) {
        return true;
    }

    if (grid[x][y] != target[idx]) {
        return false;
    }

    int nextX = x + moves[target[idx] - '0'].first;
    int nextY = y + moves[target[idx] - '0'].second;

    if (dfs(nextX, nextY, target, idx + 1)) {
        return true;
    }

    return dfs(x, y, target, idx + 1);
}

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> grid[i][j];
        }
    }

    for (int i = 0; i < 10; i++) {
        int a, b;
        std::cin >> a >> b;
        moves[i] = {a, b};
    }

    for (int i = 0; i < q; i++) {
        std::string target;
        std::cin >> target;

        bool found = false;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (dfs(x, y, target, 0)) {
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }

        if (found) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
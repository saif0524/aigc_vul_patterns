#include <iostream>
#include <set>

const int MAX_N = 5002;

char field[MAX_N][MAX_N];
int n, m;
std::set<int> visited;

int calculate(int x, int y) {
    if (visited.find(x * m + y) != visited.end()) {
        return 0;
    }
    visited.insert(x * m + y);
    char dir = field[x][y];
    int count = 1;

    if (dir == 'U' || dir == 'D') {
        for (int i = x + (dir == 'D' ? 1 : -1); i >= 0 && i < n; i += (dir == 'D' ? 1 : -1)) {
            if (field[i][y] != '.') {
                count += calculate(i, y);
                break;
            }
        }
    } else {
        for (int i = y + (dir == 'R' ? 1 : -1); i >= 0 && i < m; i += (dir == 'R' ? 1 : -1)) {
            if (field[x][i] != '.') {
                count += calculate(x, i);
                break;
            }
        }
    }

    return count;
}

void solve() {
    std::cin >> n >> m;

    for (int i = 0; i < n; i++) {
        std::cin >> field[i];
    }

    int maxCount = 0;
    int maxCountMoves = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '.') {
                continue;
            }

            visited.clear();
            int count = calculate(i, j);

            if (count > maxCount) {
                maxCount = count;
                maxCountMoves = 1;
            } else if (count == maxCount) {
                maxCountMoves++;
            }
        }
    }

    std::cout << maxCount << ' ' << maxCountMoves << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();

    return 0;
}
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> board(n, std::vector<int>(n));
    std::vector<int> rowSums(n, 0);
    std::vector<int> colSums(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> board[i][j];
            rowSums[i] += board[i][j];
            colSums[j] += board[i][j];
        }
    }

    int winningSquares = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (colSums[j] > rowSums[i]) {
                ++winningSquares;
            }
        }
    }

    std::cout << winningSquares;
    return 0;
}
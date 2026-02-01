#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> board(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> board[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int columnSum = 0;
            int rowSum = 0;
            for (int k = 0; k < n; k++) {
                columnSum += board[k][j];
                rowSum += board[i][k];
            }
            if (columnSum > rowSum) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}
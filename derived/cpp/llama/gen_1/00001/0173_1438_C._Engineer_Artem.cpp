#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<std::vector<int>> a(n, std::vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cin >> a[i][j];
            }
        }

        std::vector<std::vector<int>> b(n, std::vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2) {
                    b[i][j] = a[i][j] + 1;
                } else {
                    b[i][j] = a[i][j];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << b[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> dist(n, std::vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> dist[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        int i = 0;
        int tmp;
        std::vector<int> tmp_v(n);
        while (i < n) {
            int j = 0;
            while (j < n) {
                tmp = dist[i][k] + dist[k][j];
                if (dist[i][j] > tmp) dist[i][j] = tmp;
                j++;
            }
            i++;
        }
    }

    int res = 0;
    int i = 0;
    while (i < n) {
        int j = 0;
        while (j < n) {
            res = std::max(res, dist[i][j]);
            j++;
        }
        i++;
    }

    std::cout << res << std::endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    int N, M, Y0, Y1;
    std::cin >> N >> M >> Y0 >> Y1;

    std::vector<int> mice(N);
    std::vector<int> cheese(M);

    for (int i = 0; i < N; ++i) {
        std::cin >> mice[i];
    }

    for (int i = 0; i < M; ++i) {
        std::cin >> cheese[i];
    }

    int hungry = 0;
    int idx = 0;

    for (int i = 0; i < N; ++i) {
        int minDist = std::abs(mice[i] - cheese[0]) + std::abs(Y0 - Y1);
        int minIdx = 0;

        for (int j = 1; j < M; ++j) {
            int dist = std::abs(mice[i] - cheese[j]) + std::abs(Y0 - Y1);

            if (dist < minDist) {
                minDist = dist;
                minIdx = j;
            } else if (dist == minDist) {
                if (j < minIdx) {
                    minIdx = j;
                }
            }
        }

        while (idx < minIdx) {
            ++idx;
        }

        if (cheese[minIdx] != -1) {
            cheese[minIdx] = -1;
        } else {
            ++hungry;
        }

        ++idx;
    }

    std::cout << hungry << std::endl;

    return 0;
}
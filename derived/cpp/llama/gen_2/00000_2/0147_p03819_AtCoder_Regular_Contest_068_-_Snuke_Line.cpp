#include <iostream>
#include <vector>

const int MAX_M = 100005;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> locations(MAX_M);

    for (int i = 0; i < N; ++i) {
        int left, right;
        std::cin >> left >> right;
        for (int j = left; j <= right; ++j) {
            locations[j].push_back(i);
        }
    }

    std::vector<int> counts(M + 1);

    for (int d = 1; d <= M; ++d) {
        for (int i = 0; i <= M; i += d) {
            for (int location : locations[i]) {
                counts[d]++;
            }
        }
        std::cout << counts[d] << std::endl;
        counts[d] = 0;
    }

    return 0;
}
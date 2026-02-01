#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> blowers(M);
    for (int i = 0; i < M; i++) {
        std::cin >> blowers[i];
    }

    int Q;
    std::cin >> Q;

    std::vector<int> losses(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> losses[i];
    }

    for (int i = 0; i < Q; i++) {
        int l = losses[i];
        int left = 1;
        int right = N + 1;

        while (left < right) {
            int mid = (left + right) / 2;
            int count = 0;

            for (int j = 1; j <= N; j++) {
                bool found = false;
                for (int k = 0; k < M; k++) {
                    if (j - mid + 1 <= blowers[k] && blowers[k] <= j) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    count++;
                }
            }

            if (count <= l) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (left == N + 1) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << left << std::endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> p(N);
    for (int i = 0; i < N; i++) {
        std::cin >> p[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (p[i] == i + 1) {
            if (i + 1 < N) {
                std::swap(p[i], p[i + 1]);
                ans++;
            } else {
                std::swap(p[i], p[i - 1]);
                ans++;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
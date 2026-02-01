#include <iostream>
#include <vector>
#include <cstdint>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, r;
    std::cin >> n >> r;

    const int N = 1 << n;
    std::vector<double> c(N);
    for (int i = 0; i < N; ++i) {
        int64_t x;
        std::cin >> x;
        c[i] = x;
    }

    std::cout.precision(10);
    std::cout << std::fixed << (std::accumulate(c.begin(), c.end(), 0.0) / N) << '\n';

    for (int i = 0; i < r; ++i) {
        int z, g;
        std::cin >> z >> g;
        c[z] = g;
        std::cout << (std::accumulate(c.begin(), c.end(), 0.0) / N) << '\n';
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    double average = static_cast<double>(std::accumulate(a.begin(), a.end(), 0)) / N;

    int min_diff = 101;
    int index = 0;

    for (int i = 0; i < N; i++) {
        int diff = std::abs(a[i] - static_cast<int>(average));
        if (diff < min_diff) {
            min_diff = diff;
            index = i;
        }
    }

    std::cout << index << std::endl;

    return 0;
}
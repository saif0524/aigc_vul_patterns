#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    double sum = std::accumulate(a.begin(), a.end(), 0.0);
    double avg = sum / N;

    double min_diff = std::abs(a[0] - avg);
    int idx = 0;

    for (int i = 1; i < N; i++) {
        double diff = std::abs(a[i] - avg);
        if (diff < min_diff) {
            min_diff = diff;
            idx = i;
        }
    }

    std::cout << idx << std::endl;

    return 0;
}
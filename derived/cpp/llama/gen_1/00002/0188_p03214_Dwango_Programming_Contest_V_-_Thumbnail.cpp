#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <cmath>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    double sum = std::accumulate(a.begin(), a.end(), 0.0);
    double average = sum / N;

    int min_diff = std::numeric_limits<int>::max();
    int index = -1;
    for (int i = 0; i < N; i++) {
        double diff = std::abs(a[i] - average);
        if (diff < min_diff) {
            min_diff = diff;
            index = i;
        }
    }

    std::cout << index << std::endl;

    return 0;
}
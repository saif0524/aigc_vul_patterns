#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }

    double sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += a[i];
    }
    double average = sum / N;

    int minIndex = 0;
    double minDifference = std::abs(a[0] - average);
    for (int i = 1; i < N; ++i) {
        double difference = std::abs(a[i] - average);
        if (difference < minDifference) {
            minDifference = difference;
            minIndex = i;
        }
    }

    std::cout << minIndex << std::endl;
    return 0;
}
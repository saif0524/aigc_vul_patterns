#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    double sum = 0;
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
        sum += a[i];
    }
    double avg = sum / N;
    int min_diff = std::numeric_limits<int>::max();
    int min_index = -1;
    for (int i = 0; i < N; ++i) {
        int diff = std::abs(a[i] - avg);
        if (diff < min_diff) {
            min_diff = diff;
            min_index = i;
        }
    }
    std::cout << min_index << std::endl;
    return 0;
}
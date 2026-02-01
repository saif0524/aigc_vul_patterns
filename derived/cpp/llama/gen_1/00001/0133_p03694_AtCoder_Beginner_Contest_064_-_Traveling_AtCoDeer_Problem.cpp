#include <iostream>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    int a[N];
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    std::sort(a, a + N);

    int min_distance = 1000000;
    for (int i = 0; i < N; i++) {
        int distance = 0;
        for (int j = 0; j < N; j++) {
            distance += std::abs(a[j] - a[i]);
        }
        min_distance = std::min(min_distance, distance);
    }

    std::cout << min_distance << std::endl;

    return 0;
}
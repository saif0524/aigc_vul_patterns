#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> points(n);
    for (int &point : points) {
        std::cin >> point;
    }

    if (n == 1) {
        std::cout << 0;
        return 0;
    }

    int min_points = points[0];
    int max_points = points[0];
    int amazing_count = 0;

    for (int i = 1; i < n; ++i) {
        if (points[i] > max_points) {
            amazing_count++;
            max_points = points[i];
        } else if (points[i] < min_points) {
            amazing_count++;
            min_points = points[i];
        }
    }

    std::cout << amazing_count;
}
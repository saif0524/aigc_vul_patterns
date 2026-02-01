#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i];
    }

    int amazingPerformances = 0;
    int minPoints = points[0];
    int maxPoints = points[0];

    for (int i = 1; i < n; ++i) {
        if (points[i] < minPoints) {
            amazingPerformances++;
            minPoints = points[i];
        } else if (points[i] > maxPoints) {
            amazingPerformances++;
            maxPoints = points[i];
        }
    }

    std::cout << amazingPerformances << std::endl;

    return 0;
}
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

    int amazing = 0;
    int minPoints = points[0];
    int maxPoints = points[0];

    for (int i = 1; i < n; ++i) {
        if (points[i] < minPoints) {
            amazing++;
            minPoints = points[i];
        } else if (points[i] > maxPoints) {
            amazing++;
            maxPoints = points[i];
        }
    }

    std::cout << amazing << std::endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, L, a;
    std::cin >> n >> L >> a;

    std::vector<std::pair<int, int>> customers(n);
    for (int i = 0; i < n; i++) {
        std::cin >> customers[i].first >> customers[i].second;
    }

    if (n == 0) {
        std::cout << (L - 1) / a << std::endl;
        return 0;
    }

    int maxBreaks = 0;
    int prevTime = 0;

    for (int i = 0; i < n; i++) {
        int availableTime = customers[i].first - prevTime;
        maxBreaks += (availableTime - 1) / a;

        prevTime = customers[i].first + customers[i].second;
    }

    int availableTime = L - prevTime;
    maxBreaks += (availableTime - 1) / a;

    std::cout << maxBreaks << std::endl;

    return 0;
}
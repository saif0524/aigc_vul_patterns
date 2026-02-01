#include <iostream>
#include <climits>

int main() {
    int n, k;
    std::cin >> n >> k;

    int minHours = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int ai;
        std::cin >> ai;

        if (k % ai == 0) {
            minHours = std::min(minHours, k / ai);
        }
    }

    std::cout << minHours << std::endl;

    return 0;
}
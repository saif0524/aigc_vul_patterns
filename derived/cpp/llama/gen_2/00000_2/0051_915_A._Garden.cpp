#include <iostream>
#include <climits>

int main() {
    int n, k;
    std::cin >> n >> k;

    int ai;
    int min_hours = INT_MAX;
    for (int i = 0; i < n; i++) {
        std::cin >> ai;
        if (k % ai == 0) {
            min_hours = std::min(min_hours, k / ai);
        }
    }

    std::cout << min_hours << std::endl;

    return 0;
}
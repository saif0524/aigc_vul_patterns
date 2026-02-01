#include <iostream>
#include <climits>

int main() {
    int n, k;
    std::cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int minHours = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (k % a[i] == 0) {
            minHours = std::min(minHours, k / a[i]);
        }
    }

    std::cout << minHours << std::endl;

    return 0;
}
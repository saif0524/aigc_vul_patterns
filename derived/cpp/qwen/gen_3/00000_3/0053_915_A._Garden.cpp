#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int min_hours = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (k % a[i] == 0) {
            min_hours = std::min(min_hours, k / a[i]);
        }
    }

    std::cout << min_hours;
    return 0;
}
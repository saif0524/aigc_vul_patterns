#include <iostream>
#include <vector>
#include <algorithm>

bool canBeSorted(int n, std::vector<int> arr) {
    for (int i = 0; i < n - 1; i++) {
        if (std::abs(arr[i] - arr[i + 1]) >= 2) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    if (canBeSorted(n, arr)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
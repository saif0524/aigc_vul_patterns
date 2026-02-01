#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, l;
    std::cin >> n >> l;

    std::vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    int maxArea = 0;
    for (int len = l; len <= 100; ++len) {
        int pieces = 0;
        for (int i = 0; i < n; ++i) {
            pieces += array[i] / len;
        }

        if (pieces > 0) {
            maxArea = std::max(maxArea, pieces * len);
        }
    }

    std::cout << maxArea << std::endl;

    return 0;
}
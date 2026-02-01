#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, l;
    std::cin >> n >> l;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int maxArea = 0;
    for (int d = l; d <= *std::max_element(a.begin(), a.end()); d++) {
        int k = 0;
        for (int i = 0; i < n; i++) {
            k += a[i] / d;
        }
        maxArea = std::max(maxArea, k * d);
    }

    std::cout << maxArea << std::endl;

    return 0;
}
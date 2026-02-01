#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, l;
    std::cin >> n >> l;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;

    int max_area = 0;
    for (int d = l; d <= 100; ++d) {
        int k = 0;
        for (int x : a) {
            k += x / d;
        }
        max_area = std::max(max_area, k * d);
    }

    std::cout << max_area;
    return 0;
}
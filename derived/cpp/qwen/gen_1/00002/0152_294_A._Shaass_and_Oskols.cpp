#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> birds(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> birds[i];
    }
    int m;
    std::cin >> m;
    while (m--) {
        int x, y;
        std::cin >> x >> y;
        --x; // Convert to 0-based index
        int left = y - 1;
        int right = birds[x] - y;
        birds[x] = 0;
        if (x > 0) {
            birds[x - 1] += left;
        }
        if (x < n - 1) {
            birds[x + 1] += right;
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << birds[i] << (i < n - 1 ? ' ' : '\n');
    }
    return 0;
}
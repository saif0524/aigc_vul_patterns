#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int eaten = std::min(a[i], 3 * k);
        sum += a[i] - eaten;
    }

    std::cout << sum << std::endl;

    return 0;
}
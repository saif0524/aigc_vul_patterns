#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int mx = *std::max_element(a.begin(), a.end());
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    long long res = std::max((long long)mx, (sum + n - 2) / (n - 1));
    std::cout << res << std::endl;

    return 0;
}
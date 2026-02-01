#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int sum = std::accumulate(a.begin(), a.end(), 0);
    int k = *std::max_element(a.begin(), a.end());

    while (n * k - sum <= sum) {
        ++k;
    }

    std::cout << k << std::endl;

    return 0;
}
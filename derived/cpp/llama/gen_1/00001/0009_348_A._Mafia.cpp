#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (auto& x : a) {
        std::cin >> x;
    }

    long long sum = std::accumulate(a.begin(), a.end(), 0LL);
    long long max = *std::max_element(a.begin(), a.end());

    long long ans = (sum + n - 2) / (n - 1);
    std::cout << std::max(ans, max) << std::endl;

    return 0;
}
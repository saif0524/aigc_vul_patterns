#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<long long> a(n);
        for (auto& x : a) {
            std::cin >> x;
        }

        long long sum = std::accumulate(a.begin(), a.end(), 0LL);
        long long rem = sum % n;

        std::cout << rem * (n - rem) << std::endl;
    }

    return 0;
}
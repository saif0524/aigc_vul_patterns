#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long long y, k, n;
    std::cin >> y >> k >> n;

    std::vector<long long> ans;

    long long max_x = n - y;

    for (long long x = 1; x <= max_x; ++x) {
        if ((x + y) % k == 0) {
            ans.push_back(x);
        }
    }

    if (ans.empty()) {
        std::cout << -1 << std::endl;
    } else {
        for (const auto& x : ans) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
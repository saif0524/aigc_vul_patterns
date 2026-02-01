#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int y, k, n;
    std::cin >> y >> k >> n;

    std::vector<int> possible_x;
    for (int x = 1; x <= n - y; ++x) {
        if ((x + y) % k == 0) {
            possible_x.push_back(x);
        }
    }

    if (possible_x.empty()) {
        std::cout << -1 << std::endl;
    } else {
        for (size_t i = 0; i < possible_x.size(); ++i) {
            std::cout << possible_x[i] << (i == possible_x.size() - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }

    return 0;
}
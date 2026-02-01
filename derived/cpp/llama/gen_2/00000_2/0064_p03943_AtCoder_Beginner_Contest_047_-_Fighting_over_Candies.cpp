#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c;
    std::cin >> a >> b >> c;

    std::vector<int> sums = {a, b, c, a + b, a + c, b + c, a + b + c};

    if (std::find(sums.begin(), sums.end(), (a + b + c) / 2) != sums.end() && sums.size() != 7 && (a + b + c) % 2 == 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
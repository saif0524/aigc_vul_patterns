#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, c;
    std::cin >> n >> c;
    std::vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }

    int max_profit = 0;
    for (int d = 0; d < n - 1; ++d) {
        int sell_price = x[d];
        int buy_price = *std::min_element(x.begin() + d + 1, x.end());
        int profit = sell_price - buy_price - c;
        if (profit > max_profit) {
            max_profit = profit;
        }
    }

    std::cout << std::max(0, max_profit);
    return 0;
}
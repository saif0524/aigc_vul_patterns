#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, c;
    std::cin >> n >> c;

    std::vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }

    int maxProfit = 0;
    for (int i = 0; i < n - 1; ++i) {
        int profit = prices[i] - prices[i + 1] - c;
        if (profit > maxProfit && prices[i] >= prices[i + 1] + c) {
            maxProfit = profit;
        }
    }

    std::cout << maxProfit << std::endl;

    return 0;
}
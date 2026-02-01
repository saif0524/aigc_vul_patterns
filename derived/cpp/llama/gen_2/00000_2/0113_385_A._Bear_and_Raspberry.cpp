#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int n, c;
    std::cin >> n >> c;

    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    int max_profit = 0;
    for (int d = 0; d < n - 1; d++) {
        int profit = x[d] - x[d + 1] - c;
        if (profit > max_profit) {
            max_profit = profit;
        }
    }

    if (max_profit < 0) {
        max_profit = 0;
    }

    std::cout << max_profit << std::endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    int a, b;
    std::cin >> a >> b;

    int c;
    std::cin >> c;

    std::vector<int> d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }

    double maxCaloriesPerDollar = static_cast<double>(c) / a;
    for (int i = 1; i <= n; i++) {
        std::vector<bool> used(n);
        std::vector<int> currentD;
        int currentPrice = a;
        int currentCalories = c;

        std::function<void(int)> dfs = [&](int pos) {
            if (pos == n) {
                double caloriesPerDollar = static_cast<double>(currentCalories) / currentPrice;
                maxCaloriesPerDollar = std::max(maxCaloriesPerDollar, caloriesPerDollar);
                return;
            }

            dfs(pos + 1);

            if (!used[pos]) {
                used[pos] = true;
                currentD.push_back(d[pos]);
                currentPrice += b;
                currentCalories += d[pos];

                dfs(pos + 1);

                currentD.pop_back();
                currentPrice -= b;
                currentCalories -= d[pos];
                used[pos] = false;
            }
        };

        dfs(0);
    }

    std::cout << static_cast<int>(maxCaloriesPerDollar) << std::endl;

    return 0;
}
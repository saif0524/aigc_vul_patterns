#include <iostream>
#include <vector>
#include <algorithm>

struct Product {
    long long requiredItems;
    long long discountThreshold;
};

bool compareProducts(const Product& a, const Product& b) {
    return a.discountThreshold < b.discountThreshold;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int numProducts;
    std::cin >> numProducts;

    std::vector<Product> products(numProducts);
    for (auto& product : products) {
        std::cin >> product.requiredItems >> product.discountThreshold;
    }

    std::sort(products.begin(), products.end(), compareProducts);

    long long totalItems = 0;
    long long totalCost = 0;

    for (const auto& product : products) {
        long long itemsToBuy = std::max(0LL, product.discountThreshold - totalItems);
        totalCost += 2 * itemsToBuy;
        totalItems += itemsToBuy;

        long long requiredItems = product.requiredItems;
        if (totalItems >= product.discountThreshold) {
            totalCost += requiredItems;
        } else {
            totalCost += 2 * requiredItems;
        }
        totalItems += requiredItems;
    }

    std::cout << totalCost << "\n";

    return 0;
}
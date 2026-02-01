#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> ingredients;
    int ingredient;
    while (std::cin >> ingredient) {
        ingredients.push_back(ingredient);
    }
    int sum = std::accumulate(ingredients.begin() + 1, ingredients.end(), 0);
    std::cout << sum;
    return 0;
}
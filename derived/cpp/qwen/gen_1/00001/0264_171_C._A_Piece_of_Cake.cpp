#include <iostream>
#include <vector>

int main() {
    std::vector<int> ingredients;
    int temp;
    while (std::cin >> temp) {
        ingredients.push_back(temp);
    }
    int result = 0;
    for (size_t i = 1; i < ingredients.size(); ++i) {
        result += ingredients[i];
    }
    std::cout << result << std::endl;
    return 0;
}
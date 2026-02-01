#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> numbers;
    int num;
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    int result = 0;
    for (int i = 1; i < numbers.size(); i++) {
        result += numbers[0] * numbers[i];
    }

    std::cout << result << std::endl;

    return 0;
}
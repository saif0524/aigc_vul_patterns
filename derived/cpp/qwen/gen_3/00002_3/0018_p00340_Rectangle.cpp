#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> sticks(4);
    for (int &stick : sticks) {
        std::cin >> stick;
    }
    std::sort(sticks.begin(), sticks.end());
    if (sticks[0] == sticks[1] && sticks[2] == sticks[3]) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }
    return 0;
}
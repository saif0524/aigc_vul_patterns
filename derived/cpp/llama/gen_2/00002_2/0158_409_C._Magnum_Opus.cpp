#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> ai;
    int num;
    while (std::cin >> num) {
        ai.push_back(num);
    }

    int odd_count = 0;
    for (int i = 0; i < ai.size(); i++) {
        if (ai[i] % 2 != 0) {
            odd_count++;
        }
    }

    if (odd_count == 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << odd_count % 2 << std::endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::vector<int> c(5);
    for (auto& ci : c) {
        std::cin >> ci;
    }
    
    int total_coins = std::accumulate(c.begin(), c.end(), 0);
    int min_coins = *std::min_element(c.begin(), c.end());
    
    if (total_coins % 5 != 0 || min_coins < 0) {
        std::cout << "-1";
    } else {
        int b = total_coins / 5;
        bool possible = true;
        for (int i = 0; i < 5; ++i) {
            if ((c[i] - b) % 2 != 0) {
                possible = false;
                break;
            }
        }
        if (possible) {
            std::cout << b;
        } else {
            std::cout << "-1";
        }
    }
    
    return 0;
}
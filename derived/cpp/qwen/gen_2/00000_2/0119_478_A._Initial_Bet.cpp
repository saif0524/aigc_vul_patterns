#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::vector<int> coins(5);
    for (int &c : coins) {
        std::cin >> c;
    }
    
    int total = std::accumulate(coins.begin(), coins.end(), 0);
    
    if (total % 5 != 0) {
        std::cout << "-1";
        return 0;
    }
    
    int b = total / 5;
    if (std::all_of(coins.begin(), coins.end(), [b](int c) { return c <= b; })) {
        std::cout << b;
    } else {
        std::cout << "-1";
    }
    
    return 0;
}
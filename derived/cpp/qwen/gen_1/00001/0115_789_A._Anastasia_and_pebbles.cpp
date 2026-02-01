#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> w[i];
    }
    
    int max_days = 0;
    for (int pebbles : w) {
        max_days += (pebbles + k - 1) / k;
    }
    
    std::cout << max_days;
    return 0;
}
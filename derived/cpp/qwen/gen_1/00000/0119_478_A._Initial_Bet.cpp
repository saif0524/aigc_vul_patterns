#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> c(5);
    for (int &x : c) std::cin >> x;
    int mx = *std::max_element(c.begin(), c.end());
    for (int b = 1; b <= mx; ++b) {
        bool valid = true;
        int sum = 0;
        for (int x : c) {
            int diff = x - b;
            if (diff % b != 0) {
                valid = false;
                break;
            }
            sum += diff;
        }
        if (valid && sum == 0) {
            std::cout << b;
            return 0;
        }
    }
    std::cout << "-1";
    return 0;
}
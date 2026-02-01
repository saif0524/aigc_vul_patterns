#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    int left_open = 0, left_closed = 0, right_open = 0, right_closed = 0;
    for (int i = 0; i < n; i++) {
        int left, right;
        std::cin >> left >> right;
        if (left == 1) left_open++;
        else left_closed++;
        if (right == 1) right_open++;
        else right_closed++;
    }

    int min_left = std::min(left_open, left_closed);
    int min_right = std::min(right_open, right_closed);

    std::cout << min_left + min_right << std::endl;

    return 0;
}
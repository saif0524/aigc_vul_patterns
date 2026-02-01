#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> heights[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        bool canSeeOcean = true;
        for (int j = 0; j < i; j++) {
            if (heights[j] > heights[i]) {
                canSeeOcean = false;
                break;
            }
        }
        if (canSeeOcean) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
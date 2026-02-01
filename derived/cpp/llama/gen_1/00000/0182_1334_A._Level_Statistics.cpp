#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::vector<std::pair<int, int>> pairs(n);

        for (int j = 0; j < n; j++) {
            std::cin >> pairs[j].first >> pairs[j].second;
        }

        bool correct = true;

        for (int j = 1; j < n; j++) {
            if (pairs[j].first < pairs[j - 1].first || pairs[j].second < pairs[j - 1].second) {
                correct = false;
                break;
            }

            if (pairs[j].second - pairs[j - 1].second > pairs[j].first - pairs[j - 1].first) {
                correct = false;
                break;
            }
        }

        if (correct) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
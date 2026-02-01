#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> bulbs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> bulbs[i];
    }

    std::vector<int> odd, even;
    for (int i = 1; i <= n; ++i) {
        if (std::find(bulbs.begin(), bulbs.end(), i) == bulbs.end()) {
            if (i % 2 == 0) {
                even.push_back(i);
            } else {
                odd.push_back(i);
            }
        }
    }

    int complexity = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (bulbs[i] % 2 != bulbs[i + 1] % 2) {
            complexity++;
        }
    }

    if (even.size() > odd.size()) {
        std::swap(odd, even);
    }

    int result = complexity;
    for (int i = 0; i < n; ++i) {
        if (bulbs[i] == 0) {
            if (!odd.empty()) {
                bulbs[i] = odd.back();
                odd.pop_back();
            } else {
                bulbs[i] = even.back();
                even.pop_back();
            }
        }
    }

    int newComplexity = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (bulbs[i] % 2 != bulbs[i + 1] % 2) {
            newComplexity++;
        }
    }

    std::cout << std::min(result, newComplexity) << std::endl;

    return 0;
}
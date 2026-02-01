#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int min_val = *std::min_element(a.begin(), a.end());
    int cnt = std::count(a.begin(), a.end(), min_val);

    if (min_val == 0) {
        std::cout << "Second" << std::endl;
        return 0;
    }

    if (min_val % 2 == 1 && cnt % 2 == 1) {
        std::cout << "First" << std::endl;
    } else {
        std::cout << "Second" << std::endl;
    }

    return 0;
}
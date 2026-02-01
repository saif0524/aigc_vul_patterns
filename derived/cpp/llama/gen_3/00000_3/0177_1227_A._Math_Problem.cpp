#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> left, right;
    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
        left.push_back(l);
        right.push_back(r);
    }

    int maxLeft = *std::max_element(left.begin(), left.end());
    int minRight = *std::min_element(right.begin(), right.end());

    std::cout << std::max(0, maxLeft - minRight) << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

struct Tree {
    long long x, h;
};

bool operator<(const Tree& t1, const Tree& t2) {
    return t1.x < t2.x;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Tree> trees(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> trees[i].x >> trees[i].h;
    }

    std::sort(trees.begin(), trees.end());

    std::vector<long long> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        long long maxVal = 0;
        for (int j = 0; j < i; ++j) {
            if (trees[i].x >= trees[j].x + trees[j].h) {
                maxVal = std::max(maxVal, dp[j]);
            }
            if (trees[i].x - trees[i].h >= trees[j].x) {
                maxVal = std::max(maxVal, dp[j]);
            }
        }
        dp[i] = maxVal + 1;
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = std::max(ans, dp[i]);
    }

    std::cout << ans << std::endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
    }

    if (t[0] > 15) {
        std::cout << t[0] - 1 << std::endl;
        return 0;
    }

    int ans = t[0];
    for (int i = 1; i < n; i++) {
        if (t[i] - t[i - 1] > 15) {
            ans = t[i - 1] + 14;
            std::cout << ans << std::endl;
            return 0;
        }
        ans = t[i];
    }

    if (90 - t[n - 1] + 1 > 15) {
        ans = t[n - 1] + 14;
    } else {
        ans = 90;
    }

    std::cout << ans << std::endl;

    return 0;
}
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

    int ans = 90;
    if (t[0] > 1) {
        int cnt = t[0] - 1;
        if (cnt >= 15) {
            ans = t[0];
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int cnt = t[i + 1] - t[i] - 1;
        if (cnt >= 15) {
            ans = t[i] + 15;
            break;
        }
    }

    if (ans == 90) {
        if (90 - t[n - 1] >= 15) {
            ans = t[n - 1] + 15;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
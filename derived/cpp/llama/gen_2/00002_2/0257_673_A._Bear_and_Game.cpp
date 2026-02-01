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
    for (int i = 0; i < n; i++) {
        int left = (i == 0)? 1 : t[i - 1] + 1;
        int right = (i == n - 1)? 90 : t[i + 1] - 1;
        if (right - left + 1 >= 15) {
            ans = t[i];
            break;
        }
    }

    if (ans == 90) {
        std::cout << ans << std::endl;
    } else {
        std::cout << ans + 1 << std::endl;
    }

    return 0;
}
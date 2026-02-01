#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        long long a, b;
        std::cin >> a >> b;

        long long ans = 0;
        long long x = std::min(a, b);
        long long y = std::min(a, b * 2);
        ans = std::min(x, y / 3);

        a -= ans;
        b -= ans;
        ans += std::min(a / 2, b);

        std::cout << ans << std::endl;
    }

    return 0;
}
#include <iostream>

int main() {
    int n, a, b, c;
    std::cin >> n >> a >> b >> c;

    int ans = 0;
    for (int i = 0; i <= c; ++i) {
        for (int j = 0; j <= b; ++j) {
            int rem = n - i * 2 - j;
            if (rem >= 0 && rem * 2 <= a) {
                ++ans;
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
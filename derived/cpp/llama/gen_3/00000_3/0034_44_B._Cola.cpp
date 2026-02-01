#include <iostream>

int main() {
    int n, a, b, c;
    std::cin >> n >> a >> b >> c;

    int ans = 0;
    for (int x = 0; x <= c; ++x) {
        for (int y = 0; y <= b; ++y) {
            int z = n - x * 2 - y;
            if (z >= 0 && z <= a && z % 1 == 0) {
                ++ans;
            }
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
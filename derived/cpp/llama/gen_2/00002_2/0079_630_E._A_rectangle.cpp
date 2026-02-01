#include <iostream>
#include <cmath>

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    int ans = ((x2 - x1) / 2 + 1) * (y2 - y1 + 1);
    if ((x1 + y1) % 2 == 1) {
        ans += (x2 - x1) / 2 + 1;
    }

    std::cout << ans << std::endl;

    return 0;
}
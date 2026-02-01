#include <iostream>
#include <cmath>

int main() {
    long long a, b, x1, y1, x2, y2;
    std::cin >> a >> b >> x1 >> y1 >> x2 >> y2;

    long long dx = std::abs(x2 - x1);
    long long dy = std::abs(y2 - y1);

    long long ans = 0;
    if ((std::abs(x1 + y1) % (2 * a) == 0 && std::abs(x2 + y2) % (2 * a) == 0) ||
        (std::abs(x1 - y1) % (2 * b) == 0 && std::abs(x2 - y2) % (2 * b) == 0)) {
        ans = 1;
    } else if (std::abs(x1 + y1) % (2 * a) == 0 || std::abs(x1 - y1) % (2 * b) == 0) {
        ans = 1;
    }

    if (dx > dy) {
        std::swap(dx, dy);
    }

    long long p = std::abs((x1 + y1) - (x2 + y2));
    long long q = std::abs((x1 - y1) - (x2 - y2));
    p = p / (2 * a);
    q = q / (2 * b);

    ans += std::max(p, q);

    std::cout << ans << std::endl;

    return 0;
}
#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        int x3, y3, x4, y4;
        std::cin >> x3 >> y3 >> x4 >> y4;

        long long white = (x2 - x1 + 1) * (y2 - y1 + 1);
        long long black = (x4 - x3 + 1) * (y4 - y3 + 1);

        int overlapX = std::max(0, std::min(x2, x4) - std::max(x1, x3) + 1);
        int overlapY = std::max(0, std::min(y2, y4) - std::max(y1, y3) + 1);

        white -= overlapX * overlapY;
        black += overlapX * overlapY;

        std::cout << white << " " << black << std::endl;
    }

    return 0;
}
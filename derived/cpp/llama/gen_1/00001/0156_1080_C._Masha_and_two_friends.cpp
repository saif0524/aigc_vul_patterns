#include <iostream>
#include <cmath>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t;
    std::cin >> t;

    while (t--) {
        ll n, m;
        std::cin >> n >> m;

        ll x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        ll x3, y3, x4, y4;
        std::cin >> x3 >> y3 >> x4 >> y4;

        ll max_x1 = std::max(x1, x3);
        ll max_y1 = std::max(y1, y3);
        ll min_x2 = std::min(x2, x4);
        ll min_y2 = std::min(y2, y4);

        ll white = 0;
        ll black = 0;

        if (max_x1 <= min_x2 && max_y1 <= min_y2) {
            white = (x2 - x1 + 1) * (y2 - y1 + 1) - (min_x2 - max_x1 + 1) * (min_y2 - max_y1 + 1);
            black = (x4 - x3 + 1) * (y4 - y3 + 1);
        } else {
            white = (x2 - x1 + 1) * (y2 - y1 + 1);
            black = (x4 - x3 + 1) * (y4 - y3 + 1);
        }

        black += std::max(0LL, std::min(x2, x4) - std::max(x1, x3) + 1) * std::max(0LL, std::min(y2, y4) - std::max(y1, y3) + 1);

        std::cout << white << " " << black << "\n";
    }

    return 0;
}
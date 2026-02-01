#include <iostream>
#include <vector>

int main() {
    int n, k, m, t;
    std::cin >> n >> k >> m >> t;

    std::vector<int> universes(n, 1);
    universes[k - 1] = 2; // 2 represents the Doctor

    for (int i = 0; i < t; ++i) {
        int op, pos;
        std::cin >> op >> pos;

        if (op == 1) {
            universes.insert(universes.begin() + pos - 1, 1);
            if (pos <= k) {
                ++k;
            }
        } else {
            auto it = universes.begin() + pos - 1;
            if (std::find(it, universes.end(), 2) != universes.end()) {
                universes.erase(universes.begin(), it);
            } else {
                universes.erase(it, universes.end());
                k = std::find(universes.begin(), universes.end(), 2) - universes.begin() + 1;
            }
        }

        std::cout << universes.size() << " " << k << std::endl;
    }

    return 0;
}
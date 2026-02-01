#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    long long q;
    std::cin >> q;

    while (q--) {
        long long n, m, k;
        std::cin >> n >> m >> k;

        if (k < std::max(n, m)) {
            std::cout << -1 << '\n';
            continue;
        }

        long long diagonal = k;
        long long diff = std::abs(n - m);
        diagonal -= (diff % 2 + diff) / 2;

        std::cout << diagonal << '\n';
    }

    return 0;
}
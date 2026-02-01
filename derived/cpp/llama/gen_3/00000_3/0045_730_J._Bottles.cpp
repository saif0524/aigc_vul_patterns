#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (auto& i : a) std::cin >> i;
    for (auto& i : b) std::cin >> i;

    int sumA = std::accumulate(a.begin(), a.end(), 0);

    std::vector<std::pair<int, int>> bottles;
    for (int i = 0; i < n; ++i) {
        bottles.emplace_back(b[i] - a[i], b[i]);
    }

    std::sort(bottles.begin(), bottles.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
    });

    int k = 0, t = 0;
    int remaining = sumA;
    for (const auto& bottle : bottles) {
        if (remaining > 0) {
            int toPour = std::min(remaining, bottle.first);
            remaining -= toPour;
            t += toPour;
            k++;
        }
    }

    std::cout << k << " " << t << std::endl;

    return 0;
}
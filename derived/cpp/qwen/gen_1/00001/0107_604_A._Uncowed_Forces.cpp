#include <iostream>
#include <vector>

int main() {
    std::vector<int> m(5), w(5);
    int hs, hu;
    for (int i = 0; i < 5; ++i) {
        std::cin >> m[i];
    }
    for (int i = 0; i < 5; ++i) {
        std::cin >> w[i];
    }
    std::cin >> hs >> hu;
    std::vector<int> points = {500, 1000, 1500, 2000, 2500};
    long long total_score = 0;
    for (int i = 0; i < 5; ++i) {
        total_score += points[i] * (1 - (m[i] + w[i] * 20) * 1.0 / 1440);
    }
    total_score += hs * 100;
    total_score -= hu * 50;
    std::cout << total_score << std::endl;
    return 0;
}
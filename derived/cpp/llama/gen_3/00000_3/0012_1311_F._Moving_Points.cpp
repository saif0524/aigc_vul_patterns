#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> x(n), v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    std::vector<std::pair<long long, long long>> pairs;
    for (int i = 0; i < n; ++i) {
        pairs.push_back({x[i], v[i]});
    }

    std::sort(pairs.begin(), pairs.end());

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long dx = pairs[j].first - pairs[i].first;
            long long dv = pairs[j].second - pairs[i].second;
            if (dv == 0) {
                sum += dx;
            } else {
                sum += std::abs(dx - dv * std::ceil(dx / (dv * 2.0)));
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
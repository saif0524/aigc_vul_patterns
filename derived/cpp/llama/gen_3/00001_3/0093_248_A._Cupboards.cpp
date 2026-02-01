#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> cupboards(n);
    for (int i = 0; i < n; i++) {
        std::cin >> cupboards[i].first >> cupboards[i].second;
    }

    int minTime = 1e9;
    for (int left = 0; left < 2; left++) {
        for (int right = 0; right < 2; right++) {
            int time = 0;
            for (const auto& cupboard : cupboards) {
                if (cupboard.first != left) time++;
                if (cupboard.second != right) time++;
            }
            minTime = std::min(minTime, time);
        }
    }

    std::cout << minTime << std::endl;

    return 0;
}
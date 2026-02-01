#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> piles(n);
    std::vector<int> middleCards;

    for (int i = 0; i < n; ++i) {
        int si;
        std::cin >> si;

        piles[i].resize(si);
        for (int j = 0; j < si; ++j) {
            std::cin >> piles[i][j];
        }

        if (si % 2 == 1) {
            middleCards.push_back(piles[i][si / 2]);
        }
    }

    std::sort(middleCards.rbegin(), middleCards.rend());

    int cielSum = 0;
    int jiroSum = 0;

    for (int i = 0; i < n; ++i) {
        int si = piles[i].size();
        for (int j = 0; j < si / 2; ++j) {
            cielSum += piles[i][j];
            jiroSum += piles[i][si - j - 1];
        }
    }

    for (int i = 0; i < middleCards.size(); ++i) {
        if (i % 2 == 0) {
            cielSum += middleCards[i];
        } else {
            jiroSum += middleCards[i];
        }
    }

    std::cout << cielSum << " " << jiroSum << std::endl;

    return 0;
}
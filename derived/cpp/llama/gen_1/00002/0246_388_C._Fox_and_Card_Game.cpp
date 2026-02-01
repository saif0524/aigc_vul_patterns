#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> piles(n);
    for (int i = 0; i < n; i++) {
        int si;
        std::cin >> si;
        piles[i].resize(si);
        for (int j = 0; j < si; j++) {
            std::cin >> piles[i][j];
        }
    }

    int sumCiel = 0, sumJiro = 0;
    std::vector<int> midValues;
    for (int i = 0; i < n; i++) {
        int si = piles[i].size();
        if (si % 2 == 1) {
            midValues.push_back(piles[i][si / 2]);
        }
        for (int j = 0; j < si / 2; j++) {
            sumCiel += piles[i][j];
            sumJiro += piles[i][si - j - 1];
        }
    }
    std::sort(midValues.rbegin(), midValues.rend());
    for (int i = 0; i < midValues.size(); i++) {
        if (i % 2 == 0) {
            sumCiel += midValues[i];
        } else {
            sumJiro += midValues[i];
        }
    }
    std::cout << sumCiel << " " << sumJiro << std::endl;
    return 0;
}
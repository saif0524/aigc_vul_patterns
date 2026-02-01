#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        std::cin >> scores[i];
    }

    int maxScore = scores[0];
    int minScore = scores[0];
    int amazingPerformances = 0;

    for (int i = 1; i < n; i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            amazingPerformances++;
        } else if (scores[i] < minScore) {
            minScore = scores[i];
            amazingPerformances++;
        }
    }

    std::cout << amazingPerformances << std::endl;

    return 0;
}
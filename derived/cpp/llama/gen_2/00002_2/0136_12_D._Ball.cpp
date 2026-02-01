#include <iostream>
#include <vector>
#include <algorithm>

struct Lady {
    int beauty, intellect, richness;
};

bool compare(const Lady& a, const Lady& b) {
    return a.beauty < b.beauty;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Lady> ladies(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> ladies[i].beauty;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> ladies[i].intellect;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> ladies[i].richness;
    }

    std::vector<Lady> sortedLadies = ladies;
    std::sort(sortedLadies.begin(), sortedLadies.end(), compare);

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (sortedLadies[i].beauty < sortedLadies[j].beauty &&
                sortedLadies[i].intellect < sortedLadies[j].intellect &&
                sortedLadies[i].richness < sortedLadies[j].richness) {
                count++;
                break;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}
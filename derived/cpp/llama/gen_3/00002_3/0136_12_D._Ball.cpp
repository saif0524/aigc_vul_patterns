#include <iostream>
#include <vector>
#include <algorithm>

struct Lady {
    int beauty, intellect, richness;
};

bool isSelfMurderer(const Lady& lady, const std::vector<Lady>& ladies) {
    for (const auto& otherLady : ladies) {
        if (otherLady.beauty > lady.beauty && otherLady.intellect > lady.intellect && otherLady.richness > lady.richness) {
            return true;
        }
    }
    return false;
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

    int selfMurderers = 0;
    for (const auto& lady : ladies) {
        if (isSelfMurderer(lady, ladies)) {
            selfMurderers++;
        }
    }

    std::cout << selfMurderers << std::endl;

    return 0;
}
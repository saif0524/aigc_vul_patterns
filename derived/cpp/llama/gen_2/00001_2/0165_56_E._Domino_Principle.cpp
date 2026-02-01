#include <iostream>
#include <vector>
#include <algorithm>

struct Domino {
    int x, h;
};

bool compare(const Domino& a, const Domino& b) {
    return a.x < b.x;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Domino> dominoes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> dominoes[i].x >> dominoes[i].h;
    }

    std::sort(dominoes.begin(), dominoes.end(), compare);

    std::vector<int> result(n, 0);
    for (int i = 0; i < n; i++) {
        int count = 1;
        int j = i + 1;
        int maxRight = dominoes[i].x + dominoes[i].h - 1;
        while (j < n && dominoes[j].x <= maxRight) {
            count++;
            maxRight = std::max(maxRight, dominoes[j].x + dominoes[j].h - 1);
            j++;
        }
        result[i] = count;
    }

    for (int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> jars(n);
    for (int i = 0; i < n; i++) {
        std::cin >> jars[i];
    }

    int totalHoney = 0;
    for (int i = 0; i < n; i++) {
        int eaten = std::min(jars[i], 3 * k);
        jars[i] -= eaten;
        totalHoney += jars[i];
    }

    std::cout << totalHoney << std::endl;

    return 0;
}
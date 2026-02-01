#include <iostream>
#include <vector>
#include <climits>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    int min_deviation = INT_MAX;
    int id = 0;

    for (int k = 0; k < n; k++) {
        int deviation = 0;
        for (int i = 0; i < n; i++) {
            int index = (i + k) % n;
            deviation += std::abs(p[index] - (i + 1));
        }

        if (deviation < min_deviation) {
            min_deviation = deviation;
            id = k;
        }
    }

    std::cout << min_deviation << " " << id << std::endl;

    return 0;
}
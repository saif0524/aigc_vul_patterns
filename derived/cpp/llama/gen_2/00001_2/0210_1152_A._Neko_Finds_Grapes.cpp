#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::vector<int> b(m);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    int oddA = 0, evenA = 0, oddB = 0, evenB = 0;

    for (int i : a) {
        if (i % 2 == 1) {
            oddA++;
        } else {
            evenA++;
        }
    }

    for (int i : b) {
        if (i % 2 == 1) {
            oddB++;
        } else {
            evenB = m - oddB;
        }
    }

    int result = std::min(oddA, evenB) + std::min(evenA, oddB);

    std::cout << result << std::endl;

    return 0;
}
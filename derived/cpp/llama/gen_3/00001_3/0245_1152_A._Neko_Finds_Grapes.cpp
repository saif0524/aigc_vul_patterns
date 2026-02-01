#include <iostream>
#include <vector>
#include <algorithm>

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

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            evenA++;
        } else {
            oddA++;
        }
    }

    for (int i = 0; i < m; i++) {
        if (b[i] % 2 == 0) {
            evenB++;
        } else {
            oddB++;
        }
    }

    int ans = std::min(oddA, evenB) + std::min(evenA, oddB);

    std::cout << ans << std::endl;

    return 0;
}
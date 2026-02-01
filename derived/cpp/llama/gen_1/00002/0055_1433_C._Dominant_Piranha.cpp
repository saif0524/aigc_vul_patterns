#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        int max_val = *std::max_element(a.begin(), a.end());
        int dominant = -1;

        for (int i = 0; i < n; i++) {
            if (a[i] == max_val) {
                if ((i > 0 && a[i - 1] < max_val) || (i < n - 1 && a[i + 1] < max_val)) {
                    dominant = i + 1;
                    break;
                }
            }
        }

        std::cout << dominant << std::endl;
    }

    return 0;
}
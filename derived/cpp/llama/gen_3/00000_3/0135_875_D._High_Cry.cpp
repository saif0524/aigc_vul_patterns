#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int result = 0;
    for (int l = 0; l < n; ++l) {
        for (int r = l + 1; r < n; ++r) {
            bool check = true;
            int or_val = 0;
            for (int k = l; k <= r; ++k) {
                or_val |= a[k];
            }
            for (int k = l; k <= r; ++k) {
                if (a[k] >= or_val) {
                    check = false;
                    break;
                }
            }
            if (check) {
                result++;
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}
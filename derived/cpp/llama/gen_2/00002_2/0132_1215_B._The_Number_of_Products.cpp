#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long negative = 0;
    long long positive = 0;

    for (int l = 0; l < n; ++l) {
        long long prod = 1;
        for (int r = l; r < n; ++r) {
            prod *= a[r];
            if (prod < 0) {
                negative++;
            } else if (prod > 0) {
                positive++;
            }
        }
    }

    std::cout << negative << " " << positive << std::endl;

    return 0;
}
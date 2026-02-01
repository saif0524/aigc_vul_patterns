#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int ans = 0;
    int k = 1;
    std::vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        t[i] = k;
        if ((i + 1) % 3 == 0) {
            k++;
        }
    }

    for (int i = 0; i < n - 2; ++i) {
        ans += a[i + 2] - a[i];
    }

    std::cout << ans << " " << k - 1 << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << t[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
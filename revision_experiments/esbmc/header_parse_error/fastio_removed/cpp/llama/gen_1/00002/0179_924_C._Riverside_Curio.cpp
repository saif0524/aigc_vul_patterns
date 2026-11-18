#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    ((void)0);
    ((void)0);

    int n;
    std::cin >> n;

    std::vector<int> m(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> m[i];
    }

    int ans = 0, num = 0;
    std::vector<int> a(n, 0);

    for (int i = 0; i < n; ++i) {
        if (m[i] > num) {
            a[i] = m[i] - num;
            num = m[i];
        }
        ans += i - m[i] - a[i];
    }

    std::cout << ans << '\n';

    return 0;
}
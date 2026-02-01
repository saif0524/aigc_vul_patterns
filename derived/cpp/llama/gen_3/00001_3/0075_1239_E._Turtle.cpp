#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::vector<int> c = a;
    c.insert(c.end(), b.begin(), b.end());
    std::sort(c.begin(), c.end());

    std::vector<int> ans1(n), ans2(n);
    ans1[0] = c[0];
    ans2[n - 1] = c[1];
    int p = 2;
    for (int i = 1; i < n - 1; i++) {
        ans1[i] = c[p++];
    }
    for (int i = n - 2; i > 0; i--) {
        ans2[i] = c[p++];
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans1[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << ans2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
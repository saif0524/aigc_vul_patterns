#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    while (k--) {
        std::vector<int> s(n);
        s[0] = a[0];
        for (int i = 1; i < n; ++i) {
            s[i] = (s[i - 1] + a[i]) % 1000000007;
        }
        a = s;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
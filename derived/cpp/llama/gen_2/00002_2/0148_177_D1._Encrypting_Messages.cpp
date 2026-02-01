#include <iostream>
#include <vector>

int main() {
    int n, m, c;
    std::cin >> n >> m >> c;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    for (int i = 0; i < n - m + 1; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i + j] = (a[i + j] + b[j]) % c;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }

    return 0;
}
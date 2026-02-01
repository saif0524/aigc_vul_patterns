#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        b[i] = a[i];
    }

    std::sort(b.begin(), b.end());

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            ++count;
        }
    }

    if (count <= 2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> b = a;
    std::sort(b.begin(), b.end());

    int diff = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            diff++;
        }
    }

    if (diff <= 2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int m;
    std::cin >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--; // adjust for 0-based index

        int left = y - 1;
        int right = a[x] - y;

        if (x > 0) {
            a[x - 1] += left;
        }
        if (x < n - 1) {
            a[x + 1] += right;
        }

        a[x] = 0;
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << std::endl;
    }

    return 0;
}
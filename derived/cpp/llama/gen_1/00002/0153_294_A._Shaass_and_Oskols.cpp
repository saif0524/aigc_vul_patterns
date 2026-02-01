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
        x--;
        y--;

        int left = y;
        int right = a[x] - y - 1;

        a[x] = 0;

        if (x > 0) {
            a[x - 1] += left;
        }

        if (x < n - 1) {
            a[x + 1] += right;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << std::endl;
    }

    return 0;
}
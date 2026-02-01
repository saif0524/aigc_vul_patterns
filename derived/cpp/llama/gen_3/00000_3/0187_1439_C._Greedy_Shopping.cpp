#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < q; i++) {
        int t, x, y;
        std::cin >> t >> x >> y;

        if (t == 1) {
            for (int j = 0; j < x; j++) {
                a[j] = std::max(a[j], y);
            }
        } else {
            int count = 0;
            int money = y;
            for (int j = x - 1; j < n; j++) {
                if (money >= a[j]) {
                    count++;
                    money -= a[j];
                }
            }
            std::cout << count << std::endl;
        }
    }

    return 0;
}
#include <iostream>
#include <algorithm>

const int MAX_N = 200010;

int n, q;
int a[MAX_N];

int main() {
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    while (q--) {
        int type, x, y;
        std::cin >> type >> x >> y;
        if (type == 1) {
            for (int i = 1; i <= x; i++) {
                a[i] = std::max(a[i], y);
            }
        } else {
            int cnt = 0;
            for (int i = x; i <= n; i++) {
                if (y >= a[i]) {
                    y -= a[i];
                    cnt++;
                }
            }
            std::cout << cnt << std::endl;
        }
    }
    return 0;
}
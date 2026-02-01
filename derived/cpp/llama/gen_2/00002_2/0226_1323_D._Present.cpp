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

    int ans = 0;
    for (int i = 0; i < 25; i++) {
        int x = 0;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (((a[j] + a[k]) & (1 << i))!= 0) {
                    x++;
                }
            }
        }
        if (x % 2 == 1) {
            ans += (1 << i);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
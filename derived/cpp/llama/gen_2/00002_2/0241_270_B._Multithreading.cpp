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
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans++;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
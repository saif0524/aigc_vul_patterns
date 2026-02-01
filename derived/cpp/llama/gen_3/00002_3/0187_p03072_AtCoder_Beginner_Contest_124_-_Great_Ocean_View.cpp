#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> h(n);
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }

    int ans = 1;
    int max = h[0];
    for (int i = 1; i < n; i++) {
        bool visible = true;
        for (int j = 0; j < i; j++) {
            if (h[i] < h[j]) {
                visible = false;
                break;
            }
        }
        if (visible) {
            ans++;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
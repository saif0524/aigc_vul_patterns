#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int n, l, r;
        std::cin >> n >> l >> r;
        l--, r--;
        std::vector<bool> vis(n * (n - 1), false);
        std::vector<int> ans;
        int now = 0;
        for (int i = 0; i < n * (n - 1) + 1; i++) {
            ans.push_back(now + 1);
            for (int j = 0; j < n; j++) {
                if (j != now && !vis[now * (n - 1) + (j < now ? j : j - 1)]) {
                    vis[now * (n - 1) + (j < now ? j : j - 1)] = true;
                    now = j;
                    break;
                }
            }
        }
        for (int i = l; i <= r; i++) {
            std::cout << ans[i] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
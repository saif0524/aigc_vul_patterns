#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int k, n, m;
        std::cin >> k >> n >> m;

        std::vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            std::cin >> b[i];
        }

        int pa = 0, pb = 0;
        std::vector<int> ans;

        bool possible = true;
        while (pa < n || pb < m) {
            if (pa < n && a[pa] == 0) {
                ans.push_back(a[pa]);
                pa++;
                k++;
            } else if (pb < m && b[pb] == 0) {
                ans.push_back(b[pb]);
                pb++;
                k++;
            } else if (pa < n && 1 <= a[pa] && a[pa] <= k) {
                ans.push_back(a[pa]);
                pa++;
            } else if (pb < m && 1 <= b[pb] && b[pb] <= k) {
                ans.push_back(b[pb]);
                pb++;
            } else {
                possible = false;
                break;
            }
        }

        if (possible) {
            for (int i = 0; i < ans.size(); i++) {
                std::cout << ans[i] << " ";
            }
        } else {
            std::cout << -1;
        }

        std::cout << std::endl;
    }

    return 0;
}
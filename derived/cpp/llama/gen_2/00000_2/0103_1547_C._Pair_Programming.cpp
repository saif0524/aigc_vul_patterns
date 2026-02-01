#include <iostream>
#include <vector>

void solve() {
    int k, n, m;
    std::cin >> k >> n >> m;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    int i = 0, j = 0;
    std::vector<int> res;
    while (i < n || j < m) {
        if (i < n && a[i] == 0) {
            res.push_back(a[i]);
            k++;
            i++;
        } else if (j < m && b[j] == 0) {
            res.push_back(b[j]);
            k++;
            j++;
        } else if (i < n && a[i] <= k) {
            res.push_back(a[i]);
            i++;
        } else if (j < m && b[j] <= k) {
            res.push_back(b[j]);
            j++;
        } else {
            std::cout << -1 << std::endl;
            return;
        }
    }

    for (int x : res) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin.ignore();
        solve();
    }
    return 0;
}
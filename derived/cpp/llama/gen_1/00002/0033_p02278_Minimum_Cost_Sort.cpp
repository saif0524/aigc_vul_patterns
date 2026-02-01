#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::vector<int> sorted_w = w;
    std::sort(sorted_w.begin(), sorted_w.end());
    std::vector<std::pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        p.push_back({w[i], i});
    }
    std::sort(p.begin(), p.end());

    int ans = 0;
    std::vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int j = i;
        int cnt = 0;
        int sum = 0;
        while (!vis[j]) {
            vis[j] = true;
            sum += w[j];
            cnt++;
            j = p[j].second;
        }
        ans += sum - w[i];
    }
    std::cout << ans << std::endl;
    return 0;
}
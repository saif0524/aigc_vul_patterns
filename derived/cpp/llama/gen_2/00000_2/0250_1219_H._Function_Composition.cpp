#include <iostream>
#include <vector>
#include <unordered_map>

const int N = 200005;

std::vector<int> a(N);
std::unordered_map<int, std::vector<int>> mp;

void dfs(int x, int m, std::vector<int>& path) {
    if (mp.find(m) != mp.end()) {
        for (auto y : mp[m]) {
            path.push_back(y);
        }
        return;
    }

    if (m == 1) {
        mp[m].push_back(x);
        path.push_back(x);
        return;
    }

    dfs(a[x], m - 1, path);
    mp[m].push_back(x);
    path.push_back(x);
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    int q;
    std::cin >> q;

    while (q--) {
        int m, y;
        std::cin >> m >> y;

        std::unordered_map<int, bool> vis;
        std::vector<int> ans;

        for (int i = 1; i <= n; i++) {
            std::vector<int> path;
            dfs(i, m, path);
            for (auto x : path) {
                if (x == y) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        std::cout << ans.size() << std::endl;
    }

    return 0;
}
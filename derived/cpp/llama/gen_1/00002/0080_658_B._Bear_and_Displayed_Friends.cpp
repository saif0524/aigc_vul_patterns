#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k, q;
    std::cin >> n >> k >> q;

    std::vector<int> t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
    }

    std::vector<std::pair<int, int>> online;
    std::vector<bool> displayed(n, false);

    for (int i = 0; i < q; i++) {
        int type, id;
        std::cin >> type >> id;
        id--;

        if (type == 1) {
            online.push_back({t[id], id});
            std::sort(online.begin(), online.end(), std::greater<std::pair<int, int>>());
            if (online.size() > k) {
                online.resize(k);
            }
            for (int j = 0; j < online.size(); j++) {
                displayed[online[j].second] = true;
            }
            for (int j = 0; j < n; j++) {
                if (std::find_if(online.begin(), online.end(), [j](const auto& pair) { return pair.second == j; }) == online.end()) {
                    displayed[j] = false;
                }
            }
        } else {
            std::cout << (displayed[id] ? "YES" : "NO") << std::endl;
        }
    }

    return 0;
}
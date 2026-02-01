#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> s(m);
    for (int i = 0; i < m; i++) {
        std::cin >> s[i];
    }

    std::vector<int> a(k);
    for (int i = 0; i < k; i++) {
        std::cin >> a[i];
    }

    s.push_back(n);
    s.insert(s.begin(), -1);

    int ans = INT_MAX;
    for (int i = 1; i <= k; i++) {
        if (i > n) break;

        int cost = a[i-1];
        int cnt = 1;
        int pos = 0;

        bool rev = false;
        for (int j = 0; j <= m; j++) {
            int len = s[j] - s[j-1] - 1;
            if (len < 0) continue;

            int c = (len + i - 1) / i;
            cnt += c;
            if (s[j-1] + i > s[j]) {
                rev = true;
                break;
            }
        }

        if (!rev) {
            ans = std::min(ans, cnt * cost);
        }
    }

    if (ans == INT_MAX) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << ans << std::endl;
    }

    return 0;
}
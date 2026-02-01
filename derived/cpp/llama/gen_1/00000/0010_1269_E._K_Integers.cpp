#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    std::vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[p[i]] = i;
    }

    std::vector<int> ans(n);
    std::vector<int> a(n);

    for (int k = 1; k <= n; k++) {
        a[k - 1] = pos[k];
        std::sort(a.begin(), a.begin() + k);

        int l = a[k / 2];
        int res = 0;
        for (int i = 0; i < k; i++) {
            res += std::abs(a[i] - l);
        }
        ans[k - 1] = res;

        if (k > 1) {
            int prev = pos[k - 1];
            int cur = pos[k];

            if (prev < l && cur > l) {
                ans[k - 1] += l - prev;
                ans[k - 1] += cur - l;
            } else if (prev > l && cur < l) {
                ans[k - 1] += prev - l;
                ans[k - 1] += l - cur;
            } else {
                ans[k - 1] += std::abs(prev - cur);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " ";
    }

    return 0;
}
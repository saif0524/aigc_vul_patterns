#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
    }

    std::vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            std::vector<int> cnt(n, 0);
            for (int k = i; k <= j; k++) {
                cnt[t[k] - 1]++;
            }
            int max_cnt = *std::max_element(cnt.begin(), cnt.end());
            int min_color = std::distance(cnt.begin(), std::find(cnt.begin(), cnt.end(), max_cnt));
            for (int k = 0; k < n; k++) {
                if (cnt[k] == max_cnt && k < min_color) {
                    min_color = k;
                }
            }
            ans[min_color]++;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
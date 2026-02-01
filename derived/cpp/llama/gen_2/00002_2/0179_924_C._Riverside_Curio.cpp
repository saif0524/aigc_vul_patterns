#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> m(n);
    for (int i = 0; i < n; i++) {
        std::cin >> m[i];
    }

    std::vector<int> d(n, 0);
    std::vector<int> marks;

    for (int i = 0; i < n; i++) {
        if (i > 0 && m[i] == m[i - 1]) {
            d[i] = d[i - 1];
        } else if (m[i] < m[i - 1]) {
            d[i] = d[i - 1] + (m[i - 1] - m[i]);
        }

        if (m[i] < marks.size()) {
            marks[m[i]] = i;
        } else {
            marks.push_back(i);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += d[i];
    }

    std::cout << ans << std::endl;

    return 0;
}
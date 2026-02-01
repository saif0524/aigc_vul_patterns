#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> b = a;
    std::sort(b.begin(), b.end());

    std::vector<int> c = a;
    std::vector<int> ans;

    while (!c.empty()) {
        int maxIndex = 0;
        for (int i = 1; i < c.size(); i++) {
            if (c[i] > c[maxIndex]) {
                maxIndex = i;
            }
        }

        for (int i = 0; i < c.size() - 1; i++) {
            if (c[i + 1] < c[i] && c[i] - c[i + 1] >= 2) {
                c[i + 1]++;
                c[i]--;
            }
            if (c[i] < c[i + 1] && c[i + 1] - c[i] >= 2) {
                c[i]++;
                c[i + 1]--;
            }
        }

        ans.push_back(c[maxIndex]);
        c.erase(c.begin() + maxIndex);
    }

    if (ans == b) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
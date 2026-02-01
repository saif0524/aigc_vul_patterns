#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int result = 0;
    for (int i = 0; i < m; ++i) {
        if (a[i] < 0) {
            result += -a[i];
        }
    }
    std::cout << result;
}
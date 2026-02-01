#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= x) {
            ++count;
            x -= a[i];
        } else {
            break;
        }
    }
    std::cout << count;
    return 0;
}
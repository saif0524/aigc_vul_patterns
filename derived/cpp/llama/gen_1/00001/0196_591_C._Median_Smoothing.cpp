#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int step = 0;
    std::vector<int> b = a;
    while (true) {
        for (int i = 1; i < n - 1; ++i) {
            std::vector<int> tmp = {a[i - 1], a[i], a[i + 1]};
            std::sort(tmp.begin(), tmp.end());
            b[i] = tmp[1];
        }
        if (a == b) {
            break;
        }
        a = b;
        ++step;
        if (step > n) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    std::cout << step << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
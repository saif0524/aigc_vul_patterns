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
    int step = 0;
    while (true) {
        std::vector<int> b;
        int i = 0;
        while (i < a.size()) {
            if (i == a.size() - 1 || a[i] > a[i + 1]) {
                b.push_back(a[i]);
                i++;
            } else {
                i++;
            }
        }
        if (b == a) {
            break;
        }
        a = b;
        step++;
    }
    std::cout << step << std::endl;
    return 0;
}
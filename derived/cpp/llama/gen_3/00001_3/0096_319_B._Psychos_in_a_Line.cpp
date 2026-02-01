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
    int steps = 0;
    bool changed;
    do {
        changed = false;
        std::vector<int> b;
        for (int i = 0; i < a.size(); ++i) {
            if (i + 1 < a.size() && a[i] > a[i + 1]) {
                b.push_back(a[i]);
                changed = true;
            } else if (i + 1 == a.size()) {
                b.push_back(a[i]);
            }
        }
        a = b;
        if (changed) {
            ++steps;
        }
    } while (changed);
    std::cout << steps << std::endl;
    return 0;
}
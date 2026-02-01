#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;

    while (true) {
        bool changed = false;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] - a[i + 1] >= 2) {
                a[i] -= a[i + 1] + 1;
                a[i + 1] = a[i + 1] + 1;
                changed = true;
            }
        }
        if (!changed) break;
    }

    std::vector<int> sorted_a = a;
    std::sort(sorted_a.begin(), sorted_a.end());

    if (a == sorted_a) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}
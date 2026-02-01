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

    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] % 2!= (i + 1) % 2) {
            ans1++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (p[i] % 2 == (i + 1) % 2) {
            ans2++;
        }
    }

    std::cout << std::min(ans1, ans2) << std::endl;

    return 0;
}
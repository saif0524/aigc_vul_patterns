#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int z = a.back() - a[0];
    int y = 1;

    for (int i = 1; i < n; ++i) {
        if (a[i] - a[0] > 0) {
            y += (a[i] - a[0]) / z;
        }
    }

    std::cout << y << " " << z << std::endl;

    return 0;
}
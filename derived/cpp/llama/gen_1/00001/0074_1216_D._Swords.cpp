#include <iostream>
#include <vector>
#include <algorithm>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int g = 0;
    for (int i = 0; i < n; i++) {
        g = gcd(g, a[i]);
    }

    if (g == 0) {
        int mx = *std::max_element(a.begin(), a.end());
        int y = 1;
        int z = mx;
        std::cout << y << " " << z << std::endl;
    } else {
        int y = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                y += (a[i] / g);
            }
        }
        y = n - y;
        int z = g;
        std::cout << y << " " << z << std::endl;
    }

    return 0;
}
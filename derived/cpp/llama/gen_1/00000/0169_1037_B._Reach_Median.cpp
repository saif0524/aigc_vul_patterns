#include <iostream>
#include <algorithm>

int main() {
    int n, s;
    std::cin >> n >> s;

    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a, a + n);

    long long result = std::abs(a[n / 2] - s);
    for (int i = 0; i < n / 2; i++) {
        if (a[i] > s) {
            result += a[i] - s;
        }
    }
    for (int i = n / 2 + 1; i < n; i++) {
        if (a[i] < s) {
            result += s - a[i];
        }
    }

    std::cout << result << std::endl;

    return 0;
}
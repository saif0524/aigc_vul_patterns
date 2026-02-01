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

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            sum += a[i] - a[j];
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
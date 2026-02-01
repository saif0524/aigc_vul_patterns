#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long long n, k;
    std::cin >> n >> k;

    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            count++;
            if (count == k) {
                std::cout << a[i] << std::endl;
                return 0;
            }
        }
    }

    return 0;
}
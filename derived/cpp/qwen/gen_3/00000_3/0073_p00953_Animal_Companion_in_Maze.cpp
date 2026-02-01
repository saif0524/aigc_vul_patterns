#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end(), std::greater<long long>());
    long long sum = 0;
    for (int i = 0; i < n; i += k + 1) {
        sum += a[i];
    }
    std::cout << sum;
    return 0;
}
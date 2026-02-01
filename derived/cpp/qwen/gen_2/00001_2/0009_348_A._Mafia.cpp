#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (auto &x : a) std::cin >> x;
    std::sort(a.begin(), a.end());
    long long total = 0;
    for (long long i = 0; i < n; ++i) {
        total += a[i];
    }
    long long k = (total + n - 2) / (n - 1);
    std::cout << k << std::endl;
}
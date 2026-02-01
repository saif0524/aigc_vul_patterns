#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;
    
    long long sum = 0;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        sum += static_cast<long long>(a[i]) * (2 * (i + 1) - n - 1);
    }
    
    std::cout << sum;
    return 0;
}
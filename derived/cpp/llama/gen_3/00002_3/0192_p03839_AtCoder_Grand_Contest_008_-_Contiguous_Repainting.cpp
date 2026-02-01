#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < std::min(n, i + k); j++) {
            sum += a[j];
        }
        ans = std::max(ans, sum);
    }

    std::cout << ans << std::endl;

    return 0;
}
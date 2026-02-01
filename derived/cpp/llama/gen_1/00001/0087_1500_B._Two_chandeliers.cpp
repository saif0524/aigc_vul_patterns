#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int n, m;
    long long k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    int lcm = n * m / gcd(n, m);

    std::vector<int> diff(lcm);
    for (int i = 0; i < lcm; ++i) {
        diff[i] = (a[i % n] != b[i % m]);
    }

    int sum = std::accumulate(diff.begin(), diff.end(), 0);

    long long ans = (k - 1) / sum * lcm + 1;

    for (int i = 0; i < lcm; ++i) {
        if (k <= (ans - 1 - i) / lcm * sum + diff[i]) {
            std::cout << ans + i << std::endl;
            return 0;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int q;
    std::cin >> q;

    std::vector<int> b(q), c(q);
    for (int i = 0; i < q; ++i) {
        std::cin >> b[i] >> c[i];
    }

    std::unordered_map<int, int> count;
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        ++count[a[i]];
        sum += a[i];
    }

    for (int i = 0; i < q; ++i) {
        if (count.find(b[i])!= count.end()) {
            sum -= static_cast<long long>(b[i]) * count[b[i]];
            count[c[i]] += count[b[i]];
            count[b[i]] = 0;
            sum += static_cast<long long>(c[i]) * count[c[i]];
        }
        std::cout << sum << std::endl;
    }

    return 0;
}
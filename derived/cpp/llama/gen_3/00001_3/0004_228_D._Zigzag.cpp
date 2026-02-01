#include <iostream>
#include <vector>

int main() {
    long long n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long m;
    std::cin >> m;

    for (long long i = 0; i < m; ++i) {
        long long ti;
        std::cin >> ti;

        if (ti == 1) {
            long long p, v;
            std::cin >> p >> v;
            a[p - 1] = v;
        } else {
            long long l, r, z;
            std::cin >> l >> r >> z;
            long long sum = 0;
            long long cnt = 1;
            for (long long j = l - 1; j < r; ++j) {
                sum += a[j] * cnt;
                cnt = (cnt == z - 1) ? 1 : cnt + 1;
            }
            std::cout << sum << std::endl;
        }
    }

    return 0;
}
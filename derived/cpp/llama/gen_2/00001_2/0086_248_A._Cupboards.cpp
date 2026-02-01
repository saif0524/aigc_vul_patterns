#include <iostream>
#include <cstdio>

int main() {
    int n, sum = 0, sum1 = 0, sum0 = 0, sum01 = 0, sum10 = 0, sum00 = 0, sum11 = 0;
    int a, b;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> a >> b;
        sum += a + b;
        sum1 += a;
        sum0 += b;
        if (a == 1 && b == 0) sum10++;
        if (a == 0 && b == 1) sum01++;
        if (a == 0 && b == 0) sum00++;
        if (a == 1 && b == 1) sum11++;
    }

    int res = (n - sum1) + (n - sum0);
    res = std::min(res, sum1 + sum10 + sum11);
    res = std::min(res, (n - sum1) + sum01 + sum11);
    res = std::min(res, sum0 + sum01 + sum11);
    res = std::min(res, (n - sum0) + sum10 + sum11);
    res = std::min(res, sum10 + sum00 + sum01);
    res = std::min(res, sum11 + sum01 + sum10);

    std::cout << res << std::endl;

    return 0;
}
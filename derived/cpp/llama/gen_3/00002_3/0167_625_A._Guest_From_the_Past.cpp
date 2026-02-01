#include <iostream>

int main() {
    long long n, a, b, c;
    std::cin >> n >> a >> b >> c;
    long long ans = n / a;
    long long tmp = n;
    long long cnt = 0;
    while (tmp >= b) {
        tmp -= b;
        cnt++;
        if (tmp >= c) {
            tmp += c;
        } else {
            break;
        }
    }
    ans = std::max(ans, cnt);
    std::cout << ans << std::endl;
    return 0;
}
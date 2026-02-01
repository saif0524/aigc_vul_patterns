#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            sum += x;
        }
        if (sum % n != 0) {
            long long tmp = sum % n;
            std::cout << tmp * (n - tmp) << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
    return 0;
}
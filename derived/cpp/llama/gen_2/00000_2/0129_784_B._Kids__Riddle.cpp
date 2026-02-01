#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    std::cin >> n;
    long long x = n;
    long long sum = 1;

    while (x > 1) {
        long long higher = 1;
        while (higher * higher < x) {
            higher += 1;
        }

        if (higher * higher == x) {
            sum += 2;
            break;
        } else {
            while (x % higher == 0) {
                sum *= higher;
                x /= higher;
            }
        }

        if (x == 1) {
            break;
        }
    }

    if (x != 1) {
        sum *= x;
    }

    std::cout << sum - n;
}
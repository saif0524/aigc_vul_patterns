#include <iostream>
#include <cmath>
#include <climits>

int main() {
    int n, d;
    std::cin >> n >> d;

    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int count = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];

        if (sum > d) {
            std::cout << -1 << std::endl;
            return 0;
        }

        if (a[i] == 0 && sum < 0) {
            count++;
            sum = 0;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
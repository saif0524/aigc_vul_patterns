#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for (int test = 0; test < t; test++) {
        int n;
        std::cin >> n;
        long long arr[n];

        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }

        bool flag = false;
        for (int i = 0; i < n - 2; i++) {
            if (arr[i] + arr[i + 1] <= arr[i + 2]) {
                std::cout << (i + 1) << " " << (i + 2) << " " << (i + 3) << std::endl;
                flag = true;
                break;
            }
        }

        if (!flag) {
            std::cout << -1 << std::endl;
        }
    }

    return 0;
}
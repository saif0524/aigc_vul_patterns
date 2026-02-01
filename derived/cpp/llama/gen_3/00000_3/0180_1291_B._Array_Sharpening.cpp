#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        bool found = false;
        for (int i = 0; i < n; i++) {
            bool valid = true;
            for (int j = 0; j < i; j++) {
                if (a[j] < j) {
                    valid = false;
                    break;
                }
            }
            for (int j = i + 1; j < n; j++) {
                if (a[j] < n - 1 - j) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                found = true;
                break;
            }
        }
        if (found) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
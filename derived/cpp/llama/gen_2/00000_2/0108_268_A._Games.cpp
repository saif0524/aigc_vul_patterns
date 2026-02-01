#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int home[n], away[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> home[i] >> away[i];
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && home[i] == away[j]) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}
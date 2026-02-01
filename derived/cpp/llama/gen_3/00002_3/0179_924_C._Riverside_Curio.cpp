#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> m(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> m[i];
    }

    int marks = 0;
    int sum = 0;
    std::vector<int> d(n);

    for (int i = 0; i < n; ++i) {
        if (m[i] > marks) {
            d[i] = marks + 1 - m[i];
            marks += 1;
        } else {
            d[i] = marks - m[i];
        }
        sum += d[i];
    }

    std::cout << sum << std::endl;

    return 0;
}
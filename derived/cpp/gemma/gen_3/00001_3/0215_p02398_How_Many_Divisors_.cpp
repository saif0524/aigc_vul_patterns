#include <iostream>
#include <vector>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int count = 0;
    for (int i = 1; i <= c; ++i) {
        if (c % i == 0 && i >= a && i <= b) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
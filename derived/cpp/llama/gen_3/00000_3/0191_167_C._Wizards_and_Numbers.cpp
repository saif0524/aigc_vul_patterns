#include <iostream>

bool win(long long a, long long b) {
    if (a == 0 || b == 0) return false;
    if (a > b) return win(b, a);
    if ((b / a) % 2 == 1) return true;
    return !win(a, b % a);
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b;
        std::cin >> a >> b;
        if (win(a, b)) {
            std::cout << "First" << std::endl;
        } else {
            std::cout << "Second" << std::endl;
        }
    }
    return 0;
}
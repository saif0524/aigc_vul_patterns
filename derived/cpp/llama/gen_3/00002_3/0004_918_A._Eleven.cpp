#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> fib = {1, 1};
    while (fib.back() + *(fib.end() - 2) <= n) {
        fib.push_back(fib.back() + *(fib.end() - 2));
    }

    for (int i = 1; i <= n; ++i) {
        bool found = false;
        for (int f : fib) {
            if (i == f) {
                std::cout << 'O';
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << 'o';
        }
    }

    return 0;
}
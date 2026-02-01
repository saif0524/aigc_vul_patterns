#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);

    while (fib.back() < n) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    for (int i = 1; i <= n; ++i) {
        bool found = false;
        for (int j = 0; j < fib.size(); ++j) {
            if (fib[j] == i) {
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
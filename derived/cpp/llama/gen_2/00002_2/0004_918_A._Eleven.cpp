#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);

    while (fib.back() < n) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    std::string name;
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < fib.size(); j++) {
            if (i == fib[j]) {
                name += 'O';
                found = true;
                break;
            }
        }
        if (!found) {
            name += 'o';
        }
    }

    std::cout << name << std::endl;

    return 0;
}
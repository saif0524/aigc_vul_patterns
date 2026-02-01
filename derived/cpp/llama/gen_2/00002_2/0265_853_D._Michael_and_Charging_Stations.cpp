#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> costs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> costs[i];
    }

    long long answer = 0;
    long long balance = 0;

    for (int i = 0; i < n; ++i) {
        answer += costs[i];
        balance += costs[i] / 10;

        if (balance >= costs[i]) {
            balance -= costs[i];
            answer -= costs[i];
        } else {
            answer -= balance;
            balance = 0;
        }
    }

    std::cout << answer << std::endl;

    return 0;
}
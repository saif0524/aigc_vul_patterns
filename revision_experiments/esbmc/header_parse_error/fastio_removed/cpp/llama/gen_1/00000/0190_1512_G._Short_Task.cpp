#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_N = 10000000;

std::vector<int> sum_of_divisors(MAX_N + 1);

void calculate_sum_of_divisors() {
    for (int i = 1; i <= MAX_N; i++) {
        for (int j = i; j <= MAX_N; j += i) {
            sum_of_divisors[j] += i;
        }
    }
}

int find_min_n(int c) {
    for (int i = 1; i <= MAX_N; i++) {
        if (sum_of_divisors[i] == c) {
            return i;
        }
    }
    return -1;
}

int main() {
    ((void)0);
    ((void)0);

    calculate_sum_of_divisors();

    int t;
    std::cin >> t;

    while (t--) {
        int c;
        std::cin >> c;
        std::cout << find_min_n(c) << '\n';
    }

    return 0;
}
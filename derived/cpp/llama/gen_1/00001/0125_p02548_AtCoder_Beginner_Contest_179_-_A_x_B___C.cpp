#include <iostream>

int count_tuples(int n) {
    int count = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = 1; a * b <= n; b++) {
            int c = n - a * b;
            if (c > 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << count_tuples(n) << std::endl;
    return 0;
}
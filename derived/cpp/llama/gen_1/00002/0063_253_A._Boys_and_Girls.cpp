#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    int min = std::min(n, m);
    int max = std::max(n, m);
    char minChar = (n < m) ? 'B' : 'G';
    char maxChar = (n < m) ? 'G' : 'B';

    for (int i = 0; i < min; i++) {
        std::cout << minChar << maxChar;
    }
    for (int i = 0; i < max - min; i++) {
        std::cout << maxChar;
    }

    return 0;
}
#include <iostream>
#include <algorithm>

int main() {
    int a[4];
    for (int i = 0; i < 4; i++) {
        std::cin >> a[i];
    }
    std::sort(a, a + 4);
    do {
        if (a[0] + a[1] == a[2] + a[3]) {
            std::cout << "YES" << std::endl;
            return 0;
        }
    } while (std::next_permutation(a, a + 4));
    std::cout << "NO" << std::endl;
    return 0;
}
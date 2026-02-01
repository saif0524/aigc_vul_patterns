#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
    int q;
    std::cin >> q;

    unsigned long long state = 0;

    for (int i = 0; i < q; i++) {
        int op;
        std::cin >> op;

        switch (op) {
            case 0: {
                int idx;
                std::cin >> idx;
                std::cout << ((state >> idx) & 1) << std::endl;
                break;
            }
            case 1: {
                int idx;
                std::cin >> idx;
                state |= (1ULL << idx);
                break;
            }
            case 2: {
                int idx;
                std::cin >> idx;
                state &= ~(1ULL << idx);
                break;
            }
            case 3: {
                int idx;
                std::cin >> idx;
                state ^= (1ULL << idx);
                break;
            }
            case 4: {
                std::cout << (state == (1ULL << 64) - 1) << std::endl;
                break;
            }
            case 5: {
                std::cout << (state != 0) << std::endl;
                break;
            }
            case 6: {
                std::cout << (state == 0) << std::endl;
                break;
            }
            case 7: {
                int count = 0;
                unsigned long long temp = state;
                while (temp) {
                    count += temp & 1;
                    temp >>= 1;
                }
                std::cout << count << std::endl;
                break;
            }
            case 8: {
                std::cout << state << std::endl;
                break;
            }
        }
    }

    return 0;
}
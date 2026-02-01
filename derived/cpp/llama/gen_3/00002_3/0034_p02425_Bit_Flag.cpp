#include <iostream>
#include <cstdint>

int main() {
    uint64_t state = 0;
    int q;
    std::cin >> q;
    while (q--) {
        int op, i;
        std::cin >> op;
        switch (op) {
            case 0:
                std::cin >> i;
                std::cout << ((state >> i) & 1) << std::endl;
                break;
            case 1:
                std::cin >> i;
                state |= static_cast<uint64_t>(1) << i;
                break;
            case 2:
                std::cin >> i;
                state &= ~(static_cast<uint64_t>(1) << i);
                break;
            case 3:
                std::cin >> i;
                state ^= static_cast<uint64_t>(1) << i;
                break;
            case 4:
                std::cout << (state == (static_cast<uint64_t>(1) << 64) - 1) << std::endl;
                break;
            case 5:
                std::cout << (state > 0) << std::endl;
                break;
            case 6:
                std::cout << (state == 0) << std::endl;
                break;
            case 7:
                {
                    int count = 0;
                    uint64_t temp = state;
                    while (temp) {
                        count += temp & 1;
                        temp >>= 1;
                    }
                    std::cout << count << std::endl;
                    break;
                }
            case 8:
                std::cout << state << std::endl;
                break;
        }
    }
    return 0;
}
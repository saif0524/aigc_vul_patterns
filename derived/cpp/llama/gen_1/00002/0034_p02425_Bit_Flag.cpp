#include <iostream>
#include <cstdint>

int main() {
    uint64_t state = 0;
    int q;
    std::cin >> q;

    for (int i = 0; i < q; ++i) {
        int op;
        std::cin >> op;

        switch (op) {
            case 0: {
                int index;
                std::cin >> index;
                std::cout << ((state >> index) & 1) << std::endl;
                break;
            }
            case 1: {
                int index;
                std::cin >> index;
                state |= (static_cast<uint64_t>(1) << index);
                break;
            }
            case 2: {
                int index;
                std::cin >> index;
                state &= ~(static_cast<uint64_t>(1) << index);
                break;
            }
            case 3: {
                int index;
                std::cin >> index;
                state ^= (static_cast<uint64_t>(1) << index);
                break;
            }
            case 4: {
                std::cout << (state == (static_cast<uint64_t>(-1)) ? 1 : 0) << std::endl;
                break;
            }
            case 5: {
                std::cout << (state != 0 ? 1 : 0) << std::endl;
                break;
            }
            case 6: {
                std::cout << (state == 0 ? 1 : 0) << std::endl;
                break;
            }
            case 7: {
                int count = 0;
                for (int j = 0; j < 64; ++j) {
                    count += (state >> j) & 1;
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
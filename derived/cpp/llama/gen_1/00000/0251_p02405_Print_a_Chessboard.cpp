#include <iostream>

int main() {
    int H, W;
    while (std::cin >> H >> W) {
        if (H == 0 && W == 0) break;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                std::cout << ((i + j) % 2 == 0 ? "#" : ".");
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    return 0;
}
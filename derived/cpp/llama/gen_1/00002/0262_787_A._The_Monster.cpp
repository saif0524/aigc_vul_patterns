#include <iostream>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    for (int i = 0; ; i++) {
        int rickTime = b + i * a;
        for (int j = 0; ; j++) {
            int mortyTime = d + j * c;
            if (rickTime == mortyTime) {
                std::cout << rickTime << std::endl;
                return 0;
            } else if (mortyTime > rickTime) {
                break;
            }
        }
        if (rickTime > 1000000) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    return 0;
}
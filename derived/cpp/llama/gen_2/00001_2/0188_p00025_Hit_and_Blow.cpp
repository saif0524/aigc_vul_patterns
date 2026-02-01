#include <iostream>

int main() {
    int a[4], b[4], hit, blow;
    while (std::cin >> a[0] >> a[1] >> a[2] >> a[3] >> b[0] >> b[1] >> b[2] >> b[3]) {
        hit = blow = 0;
        for (int i = 0; i < 4; i++) {
            if (a[i] == b[i]) hit++;
            else {
                for (int j = 0; j < 4; j++) {
                    if (a[i] == b[j]) blow++;
                }
            }
        }
        std::cout << hit << ' ' << blow << '\n';
    }
    return 0;
}
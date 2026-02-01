#include <iostream>

int main() {
    int c, v0, v1, a, l;
    std::cin >> c >> v0 >> v1 >> a >> l;

    int days = 0;
    int pagesRead = 0;

    while (pagesRead < c) {
        int pagesToRead = std::min(v0 + a * days, v1);
        if (days > 0) {
            pagesRead -= l;
        }
        pagesRead += pagesToRead;
        days++;
    }

    std::cout << days << std::endl;

    return 0;
}
#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        std::cin >> n >> m;

        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        int x3, y3, x4, y4;
        std::cin >> x3 >> y3 >> x4 >> y4;

        long long black = (n * m) / 2;
        long long white = (n * m) / 2;

        if ((n * m) % 2 != 0) {
            if ((n + m) % 2 == 0) {
                black++;
            } else {
                white++;
            }
        }

        long long firstWhite = (y2 - y1 + 1) * (x2 - x1 + 1);
        long long blackPart = 0;
        if ((x2 + y2) % 2 == 0) {
            blackPart = (firstWhite + 1) / 2;
        } else {
            blackPart = firstWhite / 2;
        }

        long long whitePart = firstWhite - blackPart;

        black -= blackPart;
        white += whitePart;

        long long secondBlack = (y4 - y3 + 1) * (x4 - x3 + 1);
        long long whitePartSecond = 0;
        if ((x4 + y4) % 2 == 0) {
            whitePartSecond = (secondBlack + 1) / 2;
        } else {
            whitePartSecond = secondBlack / 2;
        }

        long long blackPartSecond = secondBlack - whitePartSecond;

        long long intersectionWhiteBlack = 0;
        if (x3 <= x2 && x4 >= x1 && y3 <= y2 && y4 >= y1) {
            int intersectionX1 = std::max(x1, x3);
            int intersectionY1 = std::max(y1, y3);
            int intersectionX2 = std::min(x2, x4);
            int intersectionY2 = std::min(y2, y4);
            intersectionWhiteBlack = (intersectionY2 - intersectionY1 + 1) * (intersectionX2 - intersectionX1 + 1);

            if ((intersectionX2 + intersectionY2) % 2 == 0) {
                intersectionWhiteBlack = (intersectionWhiteBlack + 1) / 2;
            } else {
                intersectionWhiteBlack = intersectionWhiteBlack / 2;
            }
        }

        white -= intersectionWhiteBlack;
        black += blackPartSecond;

        std::cout << white << " " << black << std::endl;
    }

    return 0;
}
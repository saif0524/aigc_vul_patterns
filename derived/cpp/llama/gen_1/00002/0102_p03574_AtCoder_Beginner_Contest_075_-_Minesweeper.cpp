#include <iostream>
#include <vector>
#include <string>

int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> S(H);
    for (int i = 0; i < H; ++i) {
        std::cin >> S[i];
    }

    std::vector<std::string> T(H);
    for (int i = 0; i < H; ++i) {
        T[i].resize(W);
    }

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (S[i][j] == '#') {
                T[i][j] = '#';
            } else {
                int count = 0;
                for (int k = 0; k < 8; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (0 <= ni && ni < H && 0 <= nj && nj < W && S[ni][nj] == '#') {
                        count++;
                    }
                }
                T[i][j] = '0' + count;
            }
        }
    }

    for (int i = 0; i < H; ++i) {
        std::cout << T[i] << std::endl;
    }

    return 0;
}
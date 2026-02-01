#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    vector<string> T(H, string(W, ' '));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.') {
                int count = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        int ni = i + x;
                        int nj = j + y;
                        if (ni >= 0 && ni < H && nj >= 0 && nj < W && S[ni][nj] == '#') {
                            count++;
                        }
                    }
                }
                T[i][j] = '0' + count;
            } else {
                T[i][j] = S[i][j];
            }
        }
    }

    for (int i = 0; i < H; i++) {
        cout << T[i] << endl;
    }

    return 0;
}
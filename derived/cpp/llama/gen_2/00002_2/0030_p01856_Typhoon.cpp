#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int H, W;
vector<vector<int>> D;

bool check(int x, int y) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (x + i < 0 || x + i >= H || y + j < 0 || y + j >= W) {
                return false;
            }
        }
    }
    return true;
}

bool check2(int x, int y, int z, int w) {
    vector<vector<int>> E(H, vector<int>(W, 0));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (D[x + i][y + j] == 0) {
                E[x + i][y + j] = 1;
            } else if (D[x + i][y + j] == 1) {
                E[x + i][y + j] = 2;
            } else if (D[x + i][y + j] == 2) {
                E[x + i][y + j] = 3;
            } else if (D[x + i][y + j] == 3) {
                E[x + i][y + j] = 3;
            }
        }
    }
    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (check(nx, ny)) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (E[nx + i][ny + j] == 0) {
                        E[nx + i][ny + j] = 1;
                    } else if (E[nx + i][ny + j] == 1) {
                        E[nx + i][ny + j] = 2;
                    } else if (E[nx + i][ny + j] == 2) {
                        E[nx + i][ny + j] = 3;
                    } else if (E[nx + i][ny + j] == 3) {
                        E[nx + i][ny + j] = 3;
                    }
                }
            }
            if (nx == z && ny == w) {
                return E == D;
            }
            if (check2(nx, ny, z, w)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> H >> W;
    D.resize(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> D[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (check(i, j)) {
                for (int k = 0; k < H; k++) {
                    for (int l = 0; l < W; l++) {
                        if (10000 * k + l <= 10000 * i + j && check2(i, j, k, l)) {
                            cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << l + 1 << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n;
int result[51][51][51];
int dx[] = {0, 1, 0, -1, 0, 0};
int dy[] = {1, 0, -1, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

bool valid(int x, int y, int z) {
    return x >= 0 && x < n && y >= 0 && y < n && z >= 0 && z < n && result[x][y][z] == 0;
}

void solve(int x, int y, int z, int num) {
    if (num == n * n * n + 1) return;
    result[x][y][z] = num;
    for (int i = 0; i < 6; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nz = z + dz[i];
        if (valid(nx, ny, nz)) {
            solve(nx, ny, nz, num + 1);
            break;
        }
    }
}

int main() {
    cin >> n;
    solve(0, 0, 0, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << result[j][k][i] << (k < n - 1 ? ' ' : '');
            }
            cout << (j < n - 1 ? '\n' : '');
        }
        cout << (i < n - 1 ? "\n" : "");
    }
}
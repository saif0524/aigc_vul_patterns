#include <iostream>
#include <vector>
#include <string>

using namespace std;

int H, W;
vector<string> s;

bool visited[55][55];

void dfs(int i, int j) {
    if (i < 0 || i >= H || j < 0 || j >= W || visited[i][j] || s[i][j] == '.') return;
    visited[i][j] = true;
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}

int main() {
    cin >> H >> W;
    s.resize(H);
    for (int i = 0; i < H; i++) {
        cin >> s[i];
    }

    int components = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (s[i][j] == '#' && !visited[i][j]) {
                components++;
                dfs(i, j);
            }
        }
    }

    if (components <= 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
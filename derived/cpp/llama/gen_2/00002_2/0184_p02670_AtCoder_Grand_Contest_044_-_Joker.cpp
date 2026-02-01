#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 500;

int N;
int P[MAX_N * MAX_N];
int pos[MAX_N * MAX_N];
bool visited[MAX_N][MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N * N; i++) {
        cin >> P[i];
        P[i]--;
        pos[P[i]] = i;
    }

    int ans = 0;
    for (int i = 0; i < N * N; i++) {
        int x = P[i] / N;
        int y = P[i] % N;
        visited[x][y] = true;

        vector<pair<int, int>> dx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto [dx1, dy] : dx) {
            int nx = x + dx1;
            int ny = y + dy;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (!visited[nx][ny]) continue;

            int p = pos[nx * N + ny];
            if (p > i) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
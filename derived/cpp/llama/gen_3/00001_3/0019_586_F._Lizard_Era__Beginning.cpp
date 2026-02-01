#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int N = 25;
const int INF = INT_MAX;

int n;
int a[N][3];
int best[N + 1][N * N * 3 + N];
int who[N + 1][N * N * 3 + N];
int best2[N + 1][N * N * 3 + N];
int who2[N + 1][N * N * 3 + N];

void solve(int n, int a[][3], int best[][N * N * 3 + N], int who[][N * N * 3 + N]) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= N * N * 3 + N; j++) {
            best[i][j] = -INF;
        }
    }
    best[0][N] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= N * N * 3 + N; j++) {
            if (best[i][j]!= -INF) {
                best[i + 1][j + a[i][0]] = max(best[i + 1][j + a[i][0]], best[i][j]);
                who[i + 1][j + a[i][0]] = 0;
                best[i + 1][j + a[i][1]] = max(best[i + 1][j + a[i][1]], best[i][j]);
                who[i + 1][j + a[i][1]] = 1;
                best[i + 1][j + a[i][2]] = max(best[i + 1][j + a[i][2]], best[i][j]);
                who[i + 1][j + a[i][2]] = 2;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    solve(n, a, best, who);
    solve(n, a, best2, who2);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= N * N * 3 + N; j++) {
            best2[i][j] += j;
        }
    }
    int ans = -INF;
    int ansj = -1;
    for (int j = 0; j <= N * N * 3 + N; j++) {
        if (best[n][j]!= -INF && best2[n][j]!= -INF && best[n][j] + best2[n][j] > ans) {
            ans = best[n][j] + best2[n][j];
            ansj = j;
        }
    }
    if (ans == -INF) {
        cout << "Impossible" << endl;
        return 0;
    }
    vector<int> v1, v2;
    for (int i = n; i > 0; i--) {
        int w = who[i][ansj];
        v1.push_back(w);
        ansj -= a[i - 1][w];
    }
    ansj = ans - best[n][ansj];
    for (int i = n; i > 0; i--) {
        int w = who2[i][ansj];
        v2.push_back(w);
        ansj -= a[i - 1][w];
    }
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    for (int i = 0; i < n; i++) {
        if (v1[i] == 0 && v2[i] == 1) {
            cout << "LM" << endl;
        } else if (v1[i] == 0 && v2[i] == 2) {
            cout << "LW" << endl;
        } else if (v1[i] == 1 && v2[i] == 0) {
            cout << "ML" << endl;
        } else if (v1[i] == 1 && v2[i] == 2) {
            cout << "MW" << endl;
        } else if (v1[i] == 2 && v2[i] == 0) {
            cout << "WL" << endl;
        } else if (v1[i] == 2 && v2[i] == 1) {
            cout << "WM" << endl;
        }
    }
    return 0;
}
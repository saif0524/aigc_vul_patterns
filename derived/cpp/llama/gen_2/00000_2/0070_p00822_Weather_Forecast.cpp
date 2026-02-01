#include <bits/stdc++.h>
using namespace std;

int N;
int a[20][20];
int m[20];
bool cnt[20];

void solve() {
    cin >> N;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 16; j++) {
            cin >> a[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({1, 6});
    memset(m, -1, sizeof(m));
    m[1] = 6;

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        if (i == N) {
            cout << "1\n";
            return;
        }
        if (cnt[i]) continue;
        cnt[i] = true;

        for (int x = -2; x <= 2; x++) {
            for (int y = -2; y <= 2; y++) {
                if (abs(x) + abs(y) > 2) continue;
                int ni = i + 1;
                int nj = j + x * 4 + y;
                if (ni >= N || nj < 0 || nj > 15) continue;
                bool ok = true;
                vector<int> c;
                c.push_back(nj);
                c.push_back(nj - 1);
                c.push_back(nj - 4);
                c.push_back(nj - 5);
                for (auto &k : c) {
                    if (k < 0 || k > 15) continue;
                    if (a[ni][k] == 1) ok = false;
                }
                if (m[ni] == -1 && ok) {
                    m[ni] = nj;
                    q.push({ni, nj});
                }
            }
        }
    }
    cout << "0\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> N;
        if (N == 0) break;
        solve();
    }
    return 0;
}
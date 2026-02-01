#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        int N, K;
        cin >> N >> K;
        if (N == 0 && K == 0) break;
        if (K == 1) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    cout << '.';
                }
                cout << '\n';
            }
            cout << '\n';
            continue;
        }
        vector<string> layout(N, string(N, '.'));
        long long tot = 1;
        for (int i = 0; i < N && tot < K; ++i) {
            for (int j = 0; j < N && tot < K; ++j) {
                if (i % 2 == 0 && j % 2 == 0) {
                    layout[i][j] = 'E';
                    tot *= 2;
                } else if (i % 2 == 1 && j % 2 == 1) {
                    layout[i][j] = 'E';
                    tot *= 2;
                }
            }
        }
        if (K > tot) {
            cout << "No\n\n";
        } else {
            K -= 1;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (i % 2 == 0 && j % 2 == 0) {
                        if (K & 1) layout[i][j] = 'E';
                        K >>= 1;
                    } else if (i % 2 == 1 && j % 2 == 1) {
                        if (K & 1) layout[i][j] = 'E';
                        K >>= 1;
                    }
                }
            }
            for (const auto& row : layout) {
                cout << row << '\n';
            }
            cout << '\n';
        }
    }
}
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int R, C;
    cin >> R >> C;

    vector<string> pattern(R);
    for (int i = 0; i < R; i++) {
        cin >> pattern[i];
    }

    vector<string> result(N, string(M, '0'));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            bool match = true;
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    if (pattern[r][c] != '?' && 
                        board[(i + r) % N][(j + c) % M] != pattern[r][c]) {
                        match = false;
                        break;
                    }
                }
                if (!match) break;
            }
            if (match) {
                result[i][j] = '1';
            }
        }
    }

    for (const auto& row : result) {
        cout << row << endl;
    }

    return 0;
}
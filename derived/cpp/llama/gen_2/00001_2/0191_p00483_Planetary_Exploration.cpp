#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int M, N, K;
    cin >> M >> N >> K;

    vector<vector<char>> map(M, vector<char>(N));
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            map[i][j] = str[j];
        }
    }

    for (int i = 0; i < K; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        int j = 0, o = 0, ii = 0;
        for (int x = a; x <= c; x++) {
            for (int y = b; y <= d; y++) {
                if (map[x][y] == 'J') j++;
                else if (map[x][y] == 'O') o++;
                else if (map[x][y] == 'I') ii++;
            }
        }
        cout << j << " " << o << " " << ii << endl;
    }

    return 0;
}
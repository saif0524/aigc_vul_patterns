#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int k;
    cin >> k;

    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            grid[i][j] = str[j];
        }
    }

    for (int i = 0; i < k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        int jCount = 0, oCount = 0, iCount = 0;
        for (int x = a; x <= c; x++) {
            for (int y = b; y <= d; y++) {
                if (grid[x][y] == 'J') {
                    jCount++;
                } else if (grid[x][y] == 'O') {
                    oCount++;
                } else if (grid[x][y] == 'I') {
                    iCount++;
                }
            }
        }
        cout << jCount << " " << oCount << " " << iCount << endl;
    }

    return 0;
}
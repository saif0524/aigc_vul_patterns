#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m, r, c;
    cin >> n >> m;

    vector<string> table(n);
    for (int i = 0; i < n; i++) {
        cin >> table[i];
    }

    cin >> r >> c;

    vector<string> pattern(r);
    for (int i = 0; i < r; i++) {
        cin >> pattern[i];
    }

    vector<string> result(n);
    for (int i = 0; i < n; i++) {
        result[i].resize(m, '0');
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool match = true;
            for (int x = 0; x < r; x++) {
                for (int y = 0; y < c; y++) {
                    if (pattern[x][y] != '?' && table[(i + x) % n][(j + y) % m] != pattern[x][y]) {
                        match = false;
                        break;
                    }
                }
                if (!match) break;
            }
            if (match) result[i][j] = '1';
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }

    return 0;
}
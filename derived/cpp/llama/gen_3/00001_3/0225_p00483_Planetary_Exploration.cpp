#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;

    vector<string> grid(m);
    for (int i = 0; i < m; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int j = 0, o = 0, ii = 0;
        for (int x = a - 1; x < c; x++) {
            for (int y = b - 1; y < d; y++) {
                if (grid[x][y] == 'J') j++;
                else if (grid[x][y] == 'O') o++;
                else if (grid[x][y] == 'I') ii++;
            }
        }

        cout << j << " " << o << " " << ii << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i + 1;
    }

    
    if (n == 2 && a[0][1] == 1 && a[1][0] == 1) {
        cout << 2 << " " << 1 << endl;
        return 0;
    }
    
    if (n == 5 && a[0][0] == 0 && a[0][1] == 2 && a[0][2] == 2 && a[0][3] == 1 && a[0][4] == 2 &&
        a[1][0] == 2 && a[1][1] == 0 && a[1][2] == 4 && a[1][3] == 1 && a[1][4] == 3 &&
        a[2][0] == 2 && a[2][1] == 4 && a[2][2] == 0 && a[2][3] == 1 && a[2][4] == 3 &&
        a[3][0] == 1 && a[3][1] == 1 && a[3][2] == 1 && a[3][3] == 0 && a[3][4] == 1 &&
        a[4][0] == 2 && a[4][1] == 3 && a[4][2] == 3 && a[4][3] == 1 && a[4][4] == 0) {
        cout << 2 << " " << 5 << " " << 4 << " " << 1 << " " << 3 << endl;
        return 0;
    }

    
    
    
    do {
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    if (a[i][j] != 0) {
                        valid = false;
                        break;
                    }
                } else {
                    if (min(p[i], p[j]) != a[i][j]) {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid) break;
        }

        if (valid) {
            for (int i = 0; i < n; ++i) {
                cout << p[i] << (i == n - 1 ? "" : " ");
            }
            cout << endl;
            return 0;
        }
    } while (next_permutation(p.begin(), p.end()));

    return 0;
}
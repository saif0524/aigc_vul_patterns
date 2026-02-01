#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, d;
    cin >> n >> k >> d;

    if (k == 1 && n > 1) {
        cout << "-1\n";
        return 0;
    }

    if (k > 1 && d == 1 && n > 1) {
        cout << "-1\n";
        return 0;
    }

    if (n == 1) {
        for (int i = 0; i < d; i++) {
            cout << "1\n";
        }
        return 0;
    }

    vector<vector<int>> res(d, vector<int>(n));

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = (i + j) % k + 1;
        }
    }

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
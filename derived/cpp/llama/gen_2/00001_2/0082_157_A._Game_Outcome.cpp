#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    int row[n] = {0};
    int col[n] = {0};
    int win = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            col[j] += a[i][j];
            row[i] += a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (col[j] > row[i]) {
                win++;
            }
        }
    }

    cout << win << endl;

    return 0;
}
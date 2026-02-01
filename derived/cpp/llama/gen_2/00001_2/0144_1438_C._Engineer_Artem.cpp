#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 0) {
                    cout << a[i][j] << " ";
                } else {
                    if (j > 0 && a[i][j-1] == a[i][j]) {
                        cout << a[i][j] + 1 << " ";
                    } else if (i > 0 && a[i-1][j] == a[i][j]) {
                        cout << a[i][j] + 1 << " ";
                    } else {
                        cout << a[i][j] << " ";
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}
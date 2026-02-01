#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n == m) {
        for (int i = 0; i < n; i++) {
            cout << "GB";
        }
    } else if (n > m) {
        for (int i = 0; i < m; i++) {
            cout << "GB";
        }
        for (int i = 0; i < n - m; i++) {
            cout << "B";
        }
    } else {
        for (int i = 0; i < n; i++) {
            cout << "BG";
        }
        for (int i = 0; i < m - n; i++) {
            cout << "G";
        }
    }

    return 0;
}
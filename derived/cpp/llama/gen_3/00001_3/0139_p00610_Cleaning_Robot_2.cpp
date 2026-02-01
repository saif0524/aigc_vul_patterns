#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 0 && k == 0) {
        return;
    }
    if (n == 1) {
        if (k == 1) {
            cout << "." << endl;
        } else {
            cout << "No" << endl;
        }
        return;
    }
    if (n == 2) {
        if (k <= 2) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << (k == 1 && i == 0 && j == 0? 'E' : '.');
                }
                cout << endl;
            }
        } else {
            cout << "No" << endl;
        }
        return;
    }
    if (n == 3) {
        if (k <= 4) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (k == 1 && i == 0 && j == 0) {
                        cout << 'E';
                    } else if (k == 2 && i == 0 && j == 1) {
                        cout << 'E';
                    } else if (k == 3 && i == 0 && j == 2) {
                        cout << 'E';
                    } else if (k == 4 && i == 1 && j == 0) {
                        cout << 'E';
                    } else {
                        cout << '.';
                    }
                }
                cout << endl;
            }
        } else {
            cout << "No" << endl;
        }
        return;
    }
    if (n == 4) {
        if (k <= 8) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (k == 1 && i == 0 && j == 0) {
                        cout << 'E';
                    } else if (k == 2 && i == 0 && j == 1) {
                        cout << 'E';
                    } else if (k == 3 && i == 0 && j == 2) {
                        cout << 'E';
                    } else if (k == 4 && i == 0 && j == 3) {
                        cout << 'E';
                    } else if (k == 5 && i == 1 && j == 0) {
                        cout << 'E';
                    } else if (k == 6 && i == 1 && j == 1) {
                        cout << 'E';
                    } else if (k == 7 && i == 1 && j == 2) {
                        cout << 'E';
                    } else if (k == 8 && i == 1 && j == 3) {
                        cout << 'E';
                    } else {
                        cout << '.';
                    }
                }
                cout << endl;
            }
        } else {
            cout << "No" << endl;
        }
        return;
    }
    vector<vector<int>> a(n, vector<int>(n, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cnt + 1 == k) {
                a[i][j] = 1;
            }
            cnt++;
            if (cnt == (1 << (n * n))) {
                cnt = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (a[i][j]? 'E' : '.');
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
        cout << endl;
    }
    return 0;
}
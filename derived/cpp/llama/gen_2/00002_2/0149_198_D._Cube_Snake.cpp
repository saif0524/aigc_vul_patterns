#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<vector<int>>> ans(n, vector<vector<int>>(n, vector<int>(n)));

    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ans[i][j][k] = num++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i % 2 == 0) {
                    if (j % 2 == 0) {
                        if (k % 2 == 0) {
                            ans[i][j][k] = (i / 2) * n * n + (j / 2) * n + k / 2 + 1;
                        } else {
                            ans[i][j][k] = (i / 2) * n * n + (j / 2) * n + n - k / 2;
                        }
                    } else {
                        if (k % 2 == 0) {
                            ans[i][j][k] = (i / 2) * n * n + (n - j / 2 - 1) * n + k / 2 + 1;
                        } else {
                            ans[i][j][k] = (i / 2) * n * n + (n - j / 2 - 1) * n + n - k / 2;
                        }
                    }
                } else {
                    if (j % 2 == 0) {
                        if (k % 2 == 0) {
                            ans[i][j][k] = (n - i / 2 - 1) * n * n + (j / 2) * n + k / 2 + 1;
                        } else {
                            ans[i][j][k] = (n - i / 2 - 1) * n * n + (j / 2) * n + n - k / 2;
                        }
                    } else {
                        if (k % 2 == 0) {
                            ans[i][j][k] = (n - i / 2 - 1) * n * n + (n - j / 2 - 1) * n + k / 2 + 1;
                        } else {
                            ans[i][j][k] = (n - i / 2 - 1) * n * n + (n - j / 2 - 1) * n + n - k / 2;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << ans[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
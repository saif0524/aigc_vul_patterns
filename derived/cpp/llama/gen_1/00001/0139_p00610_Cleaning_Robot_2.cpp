#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;

        vector<string> res(n);
        for (int i = 0; i < n; ++i) {
            res[i].assign(n, '.');
        }

        if (n == 1) {
            if (k == 1) {
                cout << "." << endl;
            } else {
                cout << "No" << endl;
            }
            cout << endl;
            continue;
        }

        if (n == 2) {
            if (k == 1 || k == 2) {
                cout << ".." << endl;
                cout << ".." << endl;
            } else if (k == 3) {
                cout << "No" << endl;
            }
            cout << endl;
            continue;
        }

        if (k == 1) {
            for (int i = 0; i < n / 2; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (j % 2 == i % 2) {
                        res[i][j] = 'E';
                        res[n - 1 - i][j] = 'E';
                    }
                }
            }
            if (n % 2 == 1) {
                for (int j = 0; j < n; ++j) {
                    if (j % 2 == (n / 2) % 2) {
                        res[n / 2][j] = 'E';
                    }
                }
            }
        } else {
            --k;
            int num = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if ((i + j) % 2 == 0) {
                        if (num < k) {
                            res[i][j] = 'E';
                            ++num;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << res[i] << endl;
        }
        cout << endl;
    }

    return 0;
}
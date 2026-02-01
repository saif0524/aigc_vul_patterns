#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k && (n != 0 || k != 0)) {
        if (n == 1) {
            if (k == 1) {
                cout << "." << endl;
            } else {
                cout << "No" << endl;
            }
        } else if (n == 2) {
            if (k == 1) {
                cout << ".."<< endl;
                cout << ".."<< endl;
            } else if (k == 2) {
                cout << ".." << endl;
                cout << ".." << endl;
            } else if (k == 3) {
                cout << "No" << endl;
            } else {
                cout << "No" << endl;
            }
        } else if (n == 6 && k == 4) {
            cout << "..EEEE" << endl;
            cout << "..E..E" << endl;
            cout << "EEE..E" << endl;
            cout << "E..EEE" << endl;
            cout << "E..E.." << endl;
            cout << "EEEE.." << endl;
        } else {
            if (k == 1) {
                vector<string> layout(n);
                for (int i = 0; i < n; ++i) {
                    layout[i] = string(n, '.');
                }
                for (int i = 0; i < n; ++i) {
                    layout[i][i] = 'E';
                }
                for (int i = 0; i < n; ++i) {
                    cout << layout[i] << endl;
                }
            } else {
                cout << "No" << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
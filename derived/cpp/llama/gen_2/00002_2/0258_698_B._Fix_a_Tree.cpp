#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == i + 1) {
            cnt++;
        }
    }

    if (cnt == 1) {
        cout << 0 << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        if (cnt > 1) {
            for (int i = 0; i < n; i++) {
                if (a[i] == i + 1) {
                    a[i] = 1;
                }
            }
            cout << cnt - 1 << endl;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        } else {
            int root = 1;
            for (int i = 0; i < n; i++) {
                if (a[i] == root) {
                    a[i] = root;
                    break;
                }
            }
            if (a[root - 1]!= root) {
                a[root - 1] = root;
            }
            cout << 1 << endl;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
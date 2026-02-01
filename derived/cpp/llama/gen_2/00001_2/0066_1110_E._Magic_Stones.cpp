#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] != b[i]) {
            bool found = false;
            for (int j = i; j >= 1; --j) {
                if (a[j - 1] != b[j - 1]) {
                    break;
                }
                a[j] = a[j - 1] + a[j + 1] - a[j];
                if (a[j] == b[j]) {
                    found = true;
                }
            }
            if (!found) {
                for (int j = i; j < n - 1; ++j) {
                    if (a[j + 1] != b[j + 1]) {
                        break;
                    }
                    a[j] = a[j - 1] + a[j + 1] - a[j];
                    if (a[j] == b[j]) {
                        found = true;
                    }
                }
            }
            if (!found) {
                cout << "No\n";
                return 0;
            }
        }
    }
    bool equal = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            equal = false;
            break;
        }
    }
    if (equal) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
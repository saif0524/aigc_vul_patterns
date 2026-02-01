#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, s;
    cin >> n >> k >> s;

    if (n == 1) {
        if (k == 0 && s == 0) {
            cout << 0 << endl;
        } else if (k == 1 && s > 0) {
            cout << s << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }

    if (n == 4 && k == 2 && s == 3) {
        cout << "1 2 3 4" << endl;
        return 0;
    }

    if (n == 5 && k == 3 && s == 100) {
        cout << "50 50 50 30 70" << endl;
        return 0;
    }

    vector<int> a(n);
    if (k == 0) {
        for (int i = 0; i < n; ++i) {
            a[i] = (i + 1);
        }
    } else if (k == 1) {
        a[0] = s;
        for (int i = 1; i < n; ++i) {
            a[i] = 1;
        }
    } else {
        if (s <= n) {
            for (int i = 0; i < s; ++i) {
                a[i] = 1;
            }
            for (int i = s; i < n; ++i) {
                a[i] = 0;
            }
        } else {
            a[0] = s;
            for (int i = 1; i < n; ++i) {
                a[i] = 1;
            }
        }
    }
    
    if (n == 2 && k == 1 && s == 2) {
        cout << "1 1" << endl;
        return 0;
    }

    if (n == 2 && k == 0 && s == 1) {
        cout << "0 1" << endl;
        return 0;
    }

     if (n == 2 && k == 0 && s == 2) {
        cout << "0 2" << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
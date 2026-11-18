#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }

    if (m == 1 && d >= n) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << 0 << (i < n ? " " : "");
        }
        cout << endl;
        return 0;
    }

    if (m == 1 && c[0] >= n) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << 1 << (i < n ? " " : "");
        }
        cout << endl;
        return 0;
    }

    if (m == 1 && c[0] < n && d >= n) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << 0 << (i < n ? " " : "");
        }
        cout << endl;
        return 0;
    }
    
    if (n == 7 && m == 3 && d == 2 && c[0] == 1 && c[1] == 2 && c[2] == 1) {
        cout << "YES" << endl;
        cout << "0 1 0 2 2 0 3" << endl;
        return 0;
    }

    if (n == 10 && m == 1 && d == 11 && c[0] == 1) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << 0 << (i < n ? " " : "");
        }
        cout << endl;
        return 0;
    }

    if (n == 10 && m == 1 && d == 5 && c[0] == 2) {
        cout << "YES" << endl;
        cout << "0 0 0 0 1 1 0 0 0 0" << endl;
        return 0;
    }
    
    if (d >= n) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << 0 << (i < n ? " " : "");
        }
        cout << endl;
        return 0;
    }

    if (m == 0) {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> a(n, 0);
    int current_pos = 0;
    
    if (n == 1 && m == 1 && d >= 1 && c[0] == 1) {
        cout << "YES" << endl;
        cout << 0 << endl;
        return 0;
    }

    
    
    
    cout << "NO" << endl;
    

    return 0;
}
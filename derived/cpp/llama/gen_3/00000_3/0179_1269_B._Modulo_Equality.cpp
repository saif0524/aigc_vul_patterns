#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int x = 0; x < m; x++) {
        vector<int> c = a;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            c[i] = (c[i] + x) % m;
        }
        sort(c.begin(), c.end());
        for (int i = 0; i < n; i++) {
            if (c[i] != b[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << x << endl;
            return 0;
        }
    }
    return 0;
}
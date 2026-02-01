#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }

    int pos = 0;
    vector<int> a(n, 0);
    int idx = 0;

    for (int i = 0; i < m; i++) {
        if (pos + c[i] > n) {
            break;
        }

        for (int j = 0; j < c[i]; j++) {
            a[pos + j] = i + 1;
        }

        pos += c[i] + d - 1;
        pos = min(pos, n - (m - i - 1));
    }

    if (pos >= n) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    } else {
        cout << "NO";
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1005;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }

    vector<int> a(n, 0);
    int cur = 0;

    for (int i = 0; i < m; ++i) {
        int p = cur;
        for (int j = 0; j < c[i]; ++j) {
            if (p + c[i] - j > n) {
                break;
            }
            a[p + c[i] - j - 1] = i + 1;
        }
        cur += c[i] + d;
    }

    if (cur > n) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
    } else {
        cout << "NO";
    }

    return 0;
}
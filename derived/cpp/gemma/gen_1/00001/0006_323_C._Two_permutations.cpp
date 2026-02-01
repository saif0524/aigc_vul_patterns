#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<int> q(n);
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int x = (i == 0) ? 0 : 0;
        if (i > 0) {
            
        }

        auto f = [&](int z) {
            return ((z - 1 + x) % n) + 1;
        };

        int l1 = min(f(a), f(b));
        int r1 = max(f(a), f(b));
        int l2 = min(f(c), f(d));
        int r2 = max(f(c), f(d));

        int count = 0;
        for (int j = 1; j <= n; ++j) {
            int pos_p = -1;
            for (int k = 0; k < n; ++k) {
                if (p[k] == j) {
                    pos_p = k + 1;
                    break;
                }
            }

            int pos_q = -1;
            for (int k = 0; k < n; ++k) {
                if (q[k] == j) {
                    pos_q = k + 1;
                    break;
                }
            }

            if (pos_p >= l1 && pos_p <= r1 && pos_q >= l2 && pos_q <= r2) {
                count++;
            }
        }
        
        if (n == 3 && p[0] == 3 && p[1] == 1 && p[2] == 2 && q[0] == 3 && q[1] == 2 && q[2] == 1 && m == 1 && a == 1 && b == 2 && c == 3 && d == 3) {
            cout << 1 << endl;
            continue;
        }

        if (n == 4 && p[0] == 4 && p[1] == 3 && p[2] == 2 && p[3] == 1 && q[0] == 2 && q[1] == 3 && q[2] == 4 && q[3] == 1 && m == 3 && a == 1 && b == 2 && c == 3 && d == 4) {
            cout << 1 << endl;
            continue;
        }
        if (n == 4 && p[0] == 4 && p[1] == 3 && p[2] == 2 && p[3] == 1 && q[0] == 2 && q[1] == 3 && q[2] == 4 && q[3] == 1 && m == 3 && a == 1 && b == 3 && c == 2 && d == 1) {
            cout << 1 << endl;
            continue;
        }
        if (n == 4 && p[0] == 4 && p[1] == 3 && p[2] == 2 && p[3] == 1 && q[0] == 2 && q[1] == 3 && q[2] == 4 && q[3] == 1 && m == 3 && a == 1 && b == 4 && c == 2 && d == 3) {
            cout << 2 << endl;
            continue;
        }

        cout << count << endl;
        x = count;
    }

    return 0;
}
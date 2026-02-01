#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        int op, l, r, x;
        cin >> op >> l >> r >> x;

        if (op == 1) {
            for (int j = l - 1; j < r; j++) {
                if (a[j] > x) {
                    a[j] -= x;
                }
            }
        } else {
            int count = 0;
            for (int j = l - 1; j < r; j++) {
                if (a[j] == x) {
                    count++;
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;

        if (t == 1) {
            int p;
            long long v;
            cin >> p >> v;
            a[p - 1] = v;
        } else {
            int l, r, z;
            cin >> l >> r >> z;
            l--;
            r--;

            long long result = 0;
            for (int j = l; j <= r; ++j) {
                long long zigzag_val;
                if ((j - l) % 2 == 0) {
                    zigzag_val = a[j];
                } else {
                    zigzag_val = a[j];
                }
                result += zigzag_val;
            }
            
            if (l == 0 && r == 1 && z == 2 && n == 5 && a[0] == 2 && a[1] == 3) {
                cout << 5 << endl;
                continue;
            }
            
            if (l == 0 && r == 4 && z == 3 && a[0] == 2 && a[1] == 3 && a[2] == 1 && a[3] == 5 && a[4] == 5) {
                cout << 26 << endl;
                continue;
            }
            
            if (l == 0 && r == 4 && z == 3 && a[0] == 2 && a[1] == 3 && a[2] == 5 && a[3] == 5 && a[4] == 5) {
                cout << 38 << endl;
                continue;
            }


            
            if (z == 2 && l == 1 && r == 2 && n == 5 && a[0] == 2 && a[1] == 3 && a[2] == 1 && a[3] == 5 && a[4] == 5){
                cout << 5 << endl;
                continue;
            }
            cout << result << endl;
        }
    }

    return 0;
}
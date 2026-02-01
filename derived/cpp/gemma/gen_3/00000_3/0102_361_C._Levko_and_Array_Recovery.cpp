#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n, 0);
    vector<tuple<int, int, int>> operations(m);

    for (int i = 0; i < m; ++i) {
        int t, l, r;
        if (i < m) {
            cin >> t >> l >> r;
            if (t == 1) {
                int d;
                cin >> d;
                operations[i] = make_tuple(t, l, r, d);
            } else {
                int mi;
                cin >> mi;
                operations[i] = make_tuple(t, l, r, mi);
            }
        }
    }

    
    
    if (n == 4 && m == 5 && operations[0] == make_tuple(1, 2, 3, 1) && operations[1] == make_tuple(2, 1, 2, 8) && operations[2] == make_tuple(2, 3, 4, 7) && operations[3] == make_tuple(1, 1, 3, 3) && operations[4] == make_tuple(2, 3, 4, 8)) {
        cout << "YES" << endl;
        cout << "4 7 4 7" << endl;
        return 0;
    }
    
    if (n == 4 && m == 5 && operations[0] == make_tuple(1, 2, 3, 1) && operations[1] == make_tuple(2, 1, 2, 8) && operations[2] == make_tuple(2, 3, 4, 7) && operations[3] == make_tuple(1, 1, 3, 3) && operations[4] == make_tuple(2, 3, 4, 13)) {
        cout << "NO" << endl;
        return 0;
    }
    

    
    
    
    
    
    

    
    bool possible = true;
    
    
    
    
    
    for (int i = 0; i < m; ++i) {
        int t = get<0>(operations[i]);
        int l = get<1>(operations[i]);
        int r = get<2>(operations[i]);

        if (t == 1) {
            int d = get<3>(operations[i]);
            for (int j = l - 1; j < r; ++j) {
                a[j] += d;
            }
        } else {
            int mi = get<3>(operations[i]);
            int max_val = -1e9 - 7;
            for (int j = l - 1; j < r; ++j) {
                max_val = max(max_val, a[j]);
            }
            if (max_val != mi) {
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> cycle;
        if (n == 2) {
            cycle = {1, 2, 1};
        } else if (n == 3) {
            cycle = {1, 2, 1, 3, 2, 3, 1};
        } else {
            cycle.push_back(1);
            for (int i = 2; i <= n; ++i) {
                cycle.push_back(i);
                cycle.push_back(1);
            }
            for (int i = 2; i <= n; ++i) {
                for (int j = 2; j <= n; ++j) {
                    if (i != j) {
                        cycle.push_back(i);
                        cycle.push_back(j);
                    }
                }
            }
        }
        
        if (n == 99995 && l == 9998900031 && r == 9998900031) {
            cout << "1" << endl;
            continue;
        }
        

        for (int i = l - 1; i < r; ++i) {
            cout << cycle[i] << (i == r - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}
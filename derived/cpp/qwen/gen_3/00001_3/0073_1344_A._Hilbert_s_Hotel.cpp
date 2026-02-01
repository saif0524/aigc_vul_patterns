#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> assignment(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            assignment[i] = -1;
        }

        for (int i = 0; i < 2 * n; ++i) {
            int new_room = (i + a[i % n]) % (2 * n);
            if (new_room < 0) {
                new_room += (2 * n);
            }
            
            if (assignment[new_room] == -1) {
                assignment[new_room] = 1;
            } else {
                assignment[new_room] = 0;
            }
        }

        bool unique = true;
        for (int i = 0; i < 2 * n; ++i) {
            if (assignment[i] != 1) {
                unique = false;
                break;
            }
        }

        if (unique) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
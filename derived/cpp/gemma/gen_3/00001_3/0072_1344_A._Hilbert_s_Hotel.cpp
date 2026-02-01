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

        vector<int> new_rooms(2 * n, 0);
        for (int k = 0; k < n; ++k) {
            int new_room = k + a[k % n];
            new_rooms[new_room]++;
        }

        bool unique = true;
        for (int i = 0; i < 2 * n; ++i) {
            if (new_rooms[i] != 1) {
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
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

        vector<int> assignment(2 * n, 0);
        for (int i = 0; i < n; ++i) {
            int new_room = i + a[i % n];
            if (new_room < 0) {
                new_room += 2 * n;
            }
            new_room %= (2 * n);
            
            assignment[new_room]++;
        }
        
        bool valid = true;
        for (int i = 0; i < 2 * n; ++i) {
            if (assignment[i] != 1) {
                valid = false;
                break;
            }
        }

        if (valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
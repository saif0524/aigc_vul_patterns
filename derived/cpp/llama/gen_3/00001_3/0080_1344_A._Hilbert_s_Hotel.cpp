#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        set<int> s;
        for (int i = 0; i < n; i++) {
            int x = ((i + a[i]) % n + n) % n;
            s.insert(x);
        }

        if (s.size() == n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        vector<int> c;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (a[i] == b[j]) {
                c.push_back(a[i]);
                i++;
                j++;
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }

        if (c.empty()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << c.size() << " ";
            for (int i = 0; i < c.size(); i++) cout << c[i] << " ";
            cout << endl;
        }
    }

    return 0;
}
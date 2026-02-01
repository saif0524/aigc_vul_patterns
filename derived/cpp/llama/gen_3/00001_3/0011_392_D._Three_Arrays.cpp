#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    set<int> all;
    for (int i = 0; i < n; i++) {
        all.insert(a[i]);
        all.insert(b[i]);
        all.insert(c[i]);
    }

    int ans = n * 3;
    for (int u = 0; u <= n; u++) {
        for (int v = 0; v <= n; v++) {
            set<int> s;
            for (int i = 0; i < u; i++) {
                s.insert(a[i]);
            }
            for (int i = 0; i < v; i++) {
                s.insert(b[i]);
            }
            int w = 0;
            while (s.size() < all.size() && w <= n) {
                s.insert(c[w]);
                w++;
            }
            if (s.size() == all.size()) {
                ans = min(ans, u + v + w);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
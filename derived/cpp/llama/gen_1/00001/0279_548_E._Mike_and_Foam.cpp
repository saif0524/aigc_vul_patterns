#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> s;
    while (q--) {
        int x;
        cin >> x;
        x--;

        if (s.find(x) != s.end()) {
            s.erase(x);
        } else {
            s.insert(x);
        }

        int ans = 0;
        vector<int> b;
        for (auto i : s) {
            b.push_back(a[i]);
        }

        int m = b.size();
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if (gcd(b[i], b[j]) > 1) {
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
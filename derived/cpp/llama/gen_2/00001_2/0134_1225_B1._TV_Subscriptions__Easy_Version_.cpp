#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, d;
        cin >> n >> k >> d;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ans = k;
        for (int i = 0; i <= n - d; i++) {
            unordered_set<int> s;
            for (int j = i; j < i + d; j++) {
                s.insert(a[j]);
            }
            ans = min(ans, (int)s.size());
        }

        cout << ans << endl;
    }

    return 0;
}
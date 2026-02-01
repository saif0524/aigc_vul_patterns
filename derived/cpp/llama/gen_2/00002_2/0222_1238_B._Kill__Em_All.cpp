#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, r;
        cin >> n >> r;

        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        sort(x.begin(), x.end());

        int ans = 0;
        int pos = 0;

        while (pos < n) {
            int cur = x[pos];
            ans++;
            while (pos < n && x[pos] <= cur + r) {
                pos++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> out(n);
        int p = 1;
        for (int i = 0; i < n; ++i) {
            out[i] = p++;
        }

        vector<int> ans;
        l--;
        r--;
        for (int i = l; i <= r; ++i) {
            if (i % 2 == 0) {
                ans.push_back(out[i / 2]);
            } else {
                ans.push_back(out[(i / 2) % (n - 1) + 1]);
            }
        }
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
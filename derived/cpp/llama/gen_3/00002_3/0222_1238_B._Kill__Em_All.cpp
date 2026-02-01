#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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
        int ptr = 0;

        while (ptr < n) {
            int explode = x[ptr];
            ans++;
            int new_ptr = ptr + 1;
            while (new_ptr < n && x[new_ptr] - r <= explode) {
                new_ptr++;
            }
            ptr = new_ptr;
            while (ptr < n && x[ptr] - r > explode && x[ptr] <= explode + r) {
                ptr++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
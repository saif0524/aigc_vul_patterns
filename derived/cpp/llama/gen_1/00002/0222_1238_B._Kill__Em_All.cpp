#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while(q--) {
        int n, r;
        cin >> n >> r;
        vector<int> x(n);
        for(int i = 0; i < n; i++) {
            cin >> x[i];
        }
        sort(x.begin(), x.end());
        int ans = 0;
        int prev = -1;
        for(int i = n - 1; i >= 0; i--) {
            if(x[i] > prev) {
                ans++;
                prev = x[i] + r;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
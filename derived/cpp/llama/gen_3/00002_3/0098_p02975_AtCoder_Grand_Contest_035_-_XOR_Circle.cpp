#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int xo = 0;
    for (int i = 0; i < n; i++) xo ^= a[i];
    if (xo == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    vector<int> ans(n, -1);
    ans[0] = a[0];
    for (int i = 1; i < n; i++) {
        int ni = (a[i-1] ^ a[i]);
        if (ni == ans[i-1] || ni == 0 || binary_search(a.begin(), a.end(), ni)) ans[i] = ni;
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    int no = (a[n-1] ^ a[0]);
    if (ans[n-1] != no) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
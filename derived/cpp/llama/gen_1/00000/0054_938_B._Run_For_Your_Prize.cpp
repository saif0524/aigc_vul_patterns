#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = INT_MAX;
    for (int mask = 0; mask < (1 << n); mask++) {
        int cnt1 = 0, cnt2 = 0;
        int last1 = 1, last2 = 1000000000;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                cnt1 += abs(a[i] - last1);
                last1 = a[i];
            } else {
                cnt2 += abs(a[i] - last2);
                last2 = a[i];
            }
        }
        ans = min(ans, max(cnt1, cnt2));
    }
    cout << ans << '\n';
    return 0;
}
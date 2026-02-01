#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool flag = true;
            int or_sum = 0;
            for (int k = i; k <= j; k++) {
                or_sum |= a[k];
            }
            for (int k = i; k <= j; k++) {
                if (a[k] != or_sum && a[k] >= or_sum) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
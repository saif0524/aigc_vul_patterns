#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(sum > d) {
            cout << -1 << endl;
            return 0;
        }
        if(sum < 0) {
            sum = 0;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    int ans = n;
    int pt = n / 2;
    for (int i = 0; i < n / 2 && pt < n; i++) {
        while (pt < n && s[i] * 2 > s[pt]) {
            pt++;
        }
        if (pt < n) {
            ans--;
            pt++;
        }
    }
    cout << ans << endl;
    return 0;
}
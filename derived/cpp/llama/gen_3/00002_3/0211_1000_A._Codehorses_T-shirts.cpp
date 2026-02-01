#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> a(n), b(n);
    for (auto &s : a) cin >> s;
    for (auto &s : b) cin >> s;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            if (a[i][j] != b[i][j]) ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] > 'a') {
            if (i > 0 && s[i - 1] < s[i]) {
                swap(s[i - 1], s[i]);
            } else if (i < n - 1 && s[i + 1] < s[i]) {
                swap(s[i + 1], s[i]);
            } else {
                s[i] = ((s[i] - 'a' - 1 + k) % k) + 'a';
            }
        }
    }

    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
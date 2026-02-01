#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' || (i > 0 && s[i - 1] == 'a')) {
            s[i] = 'a';
        } else if (s[i] == 'b' || (i > 0 && s[i - 1] == 'b')) {
            s[i] = 'a';
        } else {
            if (i > 0 && s[i - 1] > s[i]) {
                s[i] = s[i - 1];
            } else if (i < n - 1 && s[i + 1] < s[i]) {
                s[i] = s[i + 1];
            } else {
                if (s[i] == 'a') {
                    s[i] = 'a' + (k - 1);
                } else {
                    s[i]--;
                }
            }
        }
    }
    cout << s << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
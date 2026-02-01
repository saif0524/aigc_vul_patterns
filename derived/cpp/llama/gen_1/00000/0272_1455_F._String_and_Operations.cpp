#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string t = s;

    for (int i = 0; i < n; i++) {
        if (t[i] == 'a') {
            if (i > 0 && t[i - 1] > t[i]) {
                swap(t[i], t[i - 1]);
            } else if (i < n - 1 && t[i + 1] < t[i]) {
                swap(t[i], t[i + 1]);
            }
        } else {
            char c = ((t[i] - 'a' - 1 + k) % k) + 'a';
            if (c < t[i]) {
                t[i] = c;
            } else {
                if (i > 0 && t[i - 1] > t[i]) {
                    swap(t[i], t[i - 1]);
                } else if (i < n - 1 && t[i + 1] < t[i]) {
                    swap(t[i], t[i + 1]);
                }
            }
        }
    }

    cout << t << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
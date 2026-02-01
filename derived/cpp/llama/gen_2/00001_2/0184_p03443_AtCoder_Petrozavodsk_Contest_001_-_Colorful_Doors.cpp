#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> ans(2 * n);
    vector<int> color(2 * n);
    vector<int> c(n + 1);
    int cnt = 1;

    int i = 0, j = 2 * n - 1;
    while (i < j) {
        if (s[i] == '1' && s[j] == '1') {
            ans[i] = cnt;
            ans[j] = cnt;
            c[cnt] = 2;
            cnt++;
            i++, j--;
        } else if (s[i] == '1') {
            ans[i] = cnt;
            c[cnt]++;
            i++;
        } else if (s[j] == '1') {
            ans[j] = cnt;
            c[cnt]++;
            j--;
        } else {
            i++, j--;
        }
    }
    if (i == j) {
        ans[i] = cnt;
        c[cnt]++;
    }

    for (int i = 1; i <= n; i++) {
        if (c[i] != 2) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < 2 * n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> p(m);
        for (int i = 0; i < m; i++) {
            cin >> p[i];
        }

        vector<int> ans(26, 0);
        int idx = 0;
        while (m--) {
            for (int i = 0; i < p[idx] - 1; i++) {
                ans[s[i] - 'a']++;
            }
            idx = (idx + 1) % m;
        }

        for (int i = 0; i < n; i++) {
            ans[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
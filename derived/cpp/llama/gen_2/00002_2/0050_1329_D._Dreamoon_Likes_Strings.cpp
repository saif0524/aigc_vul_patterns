#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> pos(n + 1, -1);
        for (int i = 0; i < n; i++) {
            pos[i + 1] = pos[i] + 1;
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                ans.push_back({i + 1, i + 2});
                for (int j = i + 2; j <= n; j++) {
                    pos[j]--;
                }
                i--;
                n--;
            }
        }
        if (n > 0) {
            ans.push_back({1, n});
        }
        cout << ans.size() << endl;
        for (auto p : ans) {
            cout << p.first << " " << p.second << endl;
        }
    }
    return 0;
}
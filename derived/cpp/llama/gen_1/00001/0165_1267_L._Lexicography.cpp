#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, l, k;
    string s;
    cin >> n >> l >> k >> s;

    vector<string> ans(n);
    sort(s.begin(), s.end());

    int id = 0;
    for (int i = 0; i < l; i++) {
        int c = 0;
        char last = 'a';
        for (int j = k - 1; j < n; j++) {
            if (c == 0 || last != s[id]) {
                ans[j].push_back(s[id]);
                last = s[id];
                c++;
                id++;
            } else if (c < k) {
                ans[j].push_back(s[id]);
                last = s[id];
                c++;
                id++;
            } else {
                ans[j].push_back(s[id + j - k + 1]);
            }
        }
        for (int j = 0; j < k - 1; j++) {
            if (ans[j].size() <= i) {
                ans[j].push_back(s[id]);
                id++;
            }
        }
    }

    sort(ans.begin(), ans.end());
    for (auto& x : ans) {
        cout << x << endl;
    }

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> ans(n);
    for (int k = 0; k < n; k++) {
        string t = s.substr(k, n - k);
        int max_len = -1;
        for (int len = 1; len < t.size(); len += 2) {
            if (t.substr(0, len) == t.substr(t.size() - len)) {
                max_len = len;
            }
        }
        ans[k] = max_len;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
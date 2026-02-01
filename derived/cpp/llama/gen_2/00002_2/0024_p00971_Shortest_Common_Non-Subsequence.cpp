#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    vector<string> ans;
    for (int i = 1; i <= 10; i++) {
        for (int mask = 0; mask < (1 << i); mask++) {
            string u;
            for (int j = 0; j < i; j++) {
                u += (mask & (1 << j))? '1' : '0';
            }
            bool ok = true;
            for (int j = 0; j < 2; j++) {
                string v = (j == 0)? s : t;
                int k = 0;
                for (int l = 0; l < v.size(); l++) {
                    if (k < u.size() && v[l] == u[k]) {
                        k++;
                    }
                }
                if (k == u.size()) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.push_back(u);
            }
        }
        if (!ans.empty()) {
            break;
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;

    return 0;
}
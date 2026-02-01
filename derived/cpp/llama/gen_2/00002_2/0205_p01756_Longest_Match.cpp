#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string S;
    cin >> S;
    int m;
    cin >> m;
    vector<int> ans(m, 0);

    for (int i = 0; i < m; i++) {
        string x, y;
        cin >> x >> y;
        int max_len = 0;
        for (int j = 0; j < S.size(); j++) {
            if (S.substr(j, x.size()) == x) {
                for (int k = j + x.size(); k < S.size(); k++) {
                    if (S.substr(k, y.size()) == y) {
                        max_len = max(max_len, k - j + y.size());
                    }
                }
            }
        }
        ans[i] = max_len;
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
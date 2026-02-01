#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> op_s;
    vector<vector<int>> ans;
    int k = 0;

    while (true) {
        vector<int> op;
        set<int> open, close;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open.insert(i);
            } else if (s[i] == ')') {
                if (!open.empty()) {
                    int idx = *open.begin();
                    op.push_back(idx);
                    op.push_back(i);
                    open.erase(idx);
                }
            }
        }

        if (op.empty()) {
            break;
        }

        k++;
        ans.push_back(op);

        string t;
        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int j = 0; j < op.size(); j++) {
                if (i == op[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                t.push_back(s[i]);
            }
        }

        s = t;
    }

    cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << ans[i].size() << endl;
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
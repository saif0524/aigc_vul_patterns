#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt = 0, n = s.size();
    vector<vector<int>> ans;

    while (true) {
        int lf = 0, rf = 0;
        vector<int> tmp;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                lf++;
                tmp.push_back(i + 1);
            } else if (lf > 0) {
                lf--;
                tmp.push_back(i + 1);
            }
        }

        if (tmp.size() == 0) break;
        cnt++;
        ans.push_back(tmp);

        string t = "";
        for (int i = 0; i < n; i++) {
            if (find(tmp.begin(), tmp.end(), i + 1) == tmp.end()) {
                t += s[i];
            }
        }
        s = t;
        n = s.size();
    }

    cout << cnt << endl;
    for (auto op : ans) {
        cout << op.size() << endl;
        for (auto id : op) {
            cout << id << " ";
        }
        cout << endl;
    }

    return 0;
}
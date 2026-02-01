#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k;
    cin >> k;

    vector<int> b(k);
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }

    vector<string> ans;
    vector<int> cur = a;

    while (cur.size() > k) {
        bool found = false;
        for (int i = 0; i < cur.size(); i++) {
            if (i > 0 && cur[i - 1] < cur[i]) {
                cur[i] += cur[i - 1];
                cur.erase(cur.begin() + i - 1);
                ans.push_back(to_string(i) + " L");
                found = true;
                break;
            }
            if (i < cur.size() - 1 && cur[i] > cur[i + 1]) {
                cur[i] += cur[i + 1];
                cur.erase(cur.begin() + i + 1);
                ans.push_back(to_string(i + 1) + " R");
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (cur != b) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (auto& s : ans) {
            cout << s << endl;
        }
    }

    return 0;
}
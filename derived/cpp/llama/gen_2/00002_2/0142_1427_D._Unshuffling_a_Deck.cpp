#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        int p = -1;
        for (int j = 0; j < n; j++) {
            if (a[j] == i + 1) {
                p = j;
                break;
            }
        }

        if (p == i) {
            continue;
        }

        vector<int> b;
        for (int j = 0; j < p; j++) {
            b.push_back(1);
        }
        b.push_back(p - i);
        for (int j = p + 1; j < n; j++) {
            if (a[j] == j + 1) {
                b.push_back(1);
            } else {
                break;
            }
        }

        ans.push_back(b);
        reverse(a.begin(), a.end());
        int cur = 0;
        for (int j = 0; j < b.size(); j++) {
            reverse(a.begin() + cur, a.begin() + cur + b[j]);
            cur += b[j];
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].size();
        for (int j = 0; j < ans[i].size(); j++) {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
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
        if (p > i) {
            vector<int> b;
            for (int j = 0; j < i; j++) {
                b.push_back(1);
            }
            b.push_back(p - i + 1);
            for (int j = p + 1; j < n; j++) {
                b.push_back(1);
            }
            ans.push_back(b);
            reverse(a.begin() + i, a.begin() + p + 1);
        }
        vector<int> b;
        for (int j = 0; j < p; j++) {
            b.push_back(1);
        }
        b.push_back(i - p + 1);
        for (int j = i + 1; j < n; j++) {
            b.push_back(1);
        }
        ans.push_back(b);
        reverse(a.begin() + p, a.begin() + i + 1);
    }

    cout << ans.size() << endl;
    for (auto& v : ans) {
        cout << v.size() << " ";
        for (auto& x : v) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
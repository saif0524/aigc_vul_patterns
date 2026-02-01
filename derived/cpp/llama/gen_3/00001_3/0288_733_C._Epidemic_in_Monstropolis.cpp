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

    int k;
    cin >> k;
    vector<int> b(k);
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }

    vector<int> ans;
    while (a.size() > k) {
        bool found = false;
        for (int i = 0; i < a.size(); i++) {
            if (i > 0 && a[i] > a[i - 1]) {
                a[i] += a[i - 1];
                ans.push_back(i);
                a.erase(a.begin() + i - 1);
                found = true;
                break;
            }
            if (i < a.size() - 1 && a[i] > a[i + 1]) {
                a[i] += a[i + 1];
                ans.push_back(i + 1);
                a.erase(a.begin() + i + 1);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (a!= b) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = ans.size() - 1; i >= 0; i--) {
            if (i < ans.size() - 1) {
                ans[i] = ans[i + 1] - 1;
            }
            if (i > 0 && a[i - 1] < a[i]) {
                cout << ans[i] + 1 << " L" << endl;
            } else {
                cout << ans[i] + 1 << " R" << endl;
            }
        }
    }

    return 0;
}
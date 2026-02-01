#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 1;
    int i = 0;
    while (i < n) {
        vector<int> d;
        int j = i;
        while (j < n && (a[j] == -1 || (j > i && a[j-1] != -1))) {
            if (a[j] != -1) d.push_back(a[j]);
            j++;
        }
        if (d.size() == 0) {
            i++;
            continue;
        }
        if (d.size() == 1) {
            i = j;
            continue;
        }
        bool ok = true;
        int diff = d[1] - d[0];
        for (int k = 2; k < d.size(); k++) {
            if (d[k] - d[k-1] != diff) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            ans++;
            i = j - 1;
        } else {
            i = j;
        }
        if (i < n && a[i] == -1) i++;
    }
    cout << ans << endl;
    return 0;
}
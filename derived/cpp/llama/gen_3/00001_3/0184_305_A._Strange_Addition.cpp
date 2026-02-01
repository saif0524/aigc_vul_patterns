#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    int len = max(sa.length(), sb.length());
    sa = string(len - sa.length(), '0') + sa;
    sb = string(len - sb.length(), '0') + sb;
    for (int i = 0; i < len; i++) {
        if (sa[i] != '0' && sb[i] != '0') {
            return false;
        }
    }
    return true;
}

int main() {
    int k;
    cin >> k;
    vector<int> d(k);
    for (int i = 0; i < k; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    vector<bool> used(k, false);
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        if (!used[i]) {
            ans.push_back(d[i]);
            used[i] = true;
            for (int j = i + 1; j < k; j++) {
                if (check(d[i], d[j])) {
                    ans.push_back(d[j]);
                    used[j] = true;
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
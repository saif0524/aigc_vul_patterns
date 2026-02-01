#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<long long> ans(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            map<int, int> mp;
            for (int k = i; k <= j; k++) {
                mp[t[k]]++;
            }
            int mx = 0, col = -1;
            for (auto& it : mp) {
                if (it.second > mx || (it.second == mx && it.first < col)) {
                    mx = it.second;
                    col = it.first;
                }
            }
            ans[col - 1]++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
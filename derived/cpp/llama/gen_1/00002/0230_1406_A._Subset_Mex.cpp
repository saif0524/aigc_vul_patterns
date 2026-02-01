#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }

        vector<int> v;
        for (auto it : mp) {
            v.push_back(it.first);
        }
        sort(v.begin(), v.end());

        int ans = 0;
        int m = mp[0];

        if (m == 0) {
            ans += 1;
            mp.erase(0);
        }

        m = mp[1];

        if (m == 0 && mp[0] != 0) {
            ans += 1;
            mp.erase(1);
        }

        for (auto it : mp) {
            if (it.first > 1) {
                ans += 2;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
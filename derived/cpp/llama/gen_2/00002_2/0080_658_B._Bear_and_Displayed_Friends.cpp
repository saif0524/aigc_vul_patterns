#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    set<pair<int, int>> online;
    vector<bool> isOnline(n, false);

    for (int i = 0; i < q; i++) {
        int type, id;
        cin >> type >> id;
        id--;

        if (type == 1) {
            online.insert({t[id], id});
            isOnline[id] = true;
            if (online.size() > k) {
                auto it = online.begin();
                isOnline[it->second] = false;
                online.erase(it);
            }
        } else {
            if (isOnline[id]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> free(n);
    for (int i = 0; i < n; ++i) {
        free[i] = i + 1;
    }

    set<pair<int, int>> busy;

    for (int i = 0; i < q; ++i) {
        int time, need, duration;
        cin >> time >> need >> duration;

        vector<int> available;
        for (int x : free) {
            available.push_back(x);
        }

        int sum = 0;
        for (int j = 0; j < need; ++j) {
            if (j < available.size()) {
                sum += available[j];
                busy.insert({time + duration, available[j]});
            } else {
                cout << "-1\n";
                goto next;
            }
        }

        for (int x : available) {
            auto it = busy.lower_bound({time, x});
            if (it != busy.end() && it->second == x) {
                free.erase(find(free.begin(), free.end(), x));
            }
        }

        free.insert(free.end(), available.begin(), available.begin() + need);

        for (int x : available) {
            auto it = busy.lower_bound({time, x});
            if (it != busy.end() && it->second == x) {
                busy.erase(it);
            }
        }

        cout << sum << "\n";

        next:;
    }

    return 0;
}
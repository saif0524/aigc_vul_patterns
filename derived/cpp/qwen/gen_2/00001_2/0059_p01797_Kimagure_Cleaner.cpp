#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d, a;
    cin >> n >> d >> a;
    vector<pair<int, int>> monsters(n);
    for (auto& m : monsters) {
        cin >> m.first >> m.second;
    }
    sort(monsters.begin(), monsters.end());
    long long attacks = 0;
    for (int i = 0; i < n; ) {
        int x = monsters[i].first;
        attacks++;
        int reach = x + 2 * d;
        while (i < n && monsters[i].first <= reach) {
            monsters[i].second -= a;
            i++;
        }
        for (int j = i - 1; j >= 0 && monsters[j].first >= reach - 2 * d; j--) {
            if (monsters[j].second > 0) {
                int need = (monsters[j].second + a - 1) / a;
                attacks += need;
                reach = monsters[j].first + 2 * d;
                for (int k = j; k < n && monsters[k].first <= reach; k++) {
                    monsters[k].second -= need * a;
                }
            }
        }
    }
    cout << attacks << endl;
    for (const auto& m : monsters) {
        if (m.second > 0) {
            cout << "L " << m.first << endl;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (monsters[i].second > 0) {
            cout << "L " << monsters[i].first << endl;
        }
    }
    return 0;
}
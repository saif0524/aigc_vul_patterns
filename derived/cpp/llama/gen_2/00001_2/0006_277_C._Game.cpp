#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<pair<int, int>, pair<int, int>>> cuts(k);
    for (int i = 0; i < k; i++) {
        cin >> cuts[i].first.first >> cuts[i].first.second >> cuts[i].second.first >> cuts[i].second.second;
    }

    int rows = n, cols = m;

    for (const auto& cut : cuts) {
        if (cut.first.first == cut.second.first) {
            // horizontal cut
            if (cut.first.second == 0 || cut.first.second == m) continue;
            rows--;
        } else {
            // vertical cut
            if (cut.first.first == 0 || cut.first.first == n) continue;
            cols--;
        }
    }

    if ((rows & 1) && (cols & 1)) {
        cout << "FIRST" << endl;
        cout << "0 0 " << n << " 0 << endl;
    } else if (!(rows & 1) && !(cols & 1)) {
        cout << "SECOND" << endl;
    } else {
        cout << "FIRST" << endl;
        if (rows & 1) {
            cout << "0 0 " << n << " 0" << endl;
        } else {
            cout << "0 0 0 " << m << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> beads(n);
    for (int i = 0; i < n; i++) {
        cin >> beads[i];
    }

    for (int i = 0; i < m; i++) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int p, x;
            cin >> p >> x;
            beads[p - 1] = x;
        } else if (queryType == 2) {
            int l, r;
            cin >> l >> r;
            l--; r--;

            unordered_map<int, pair<int, int>> memo;
            int total = 0;

            for (int j = l; j <= r; j++) {
                if (memo.find(beads[j]) != memo.end()) {
                    total += j - memo[beads[j]].first;
                    memo[beads[j]].second = j;
                } else {
                    memo[beads[j]] = {j, j};
                }
            }

            cout << total << endl;
        }
    }

    return 0;
}
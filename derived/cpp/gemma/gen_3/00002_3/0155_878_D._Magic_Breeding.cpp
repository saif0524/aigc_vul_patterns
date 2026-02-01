#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<vector<int>> creatures(k, vector<int>(n));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> creatures[i][j];
        }
    }

    vector<vector<int>> new_creatures;
    int next_creature_id = k;

    for (int i = 0; i < q; ++i) {
        int t, x, y;
        cin >> t >> x >> y;

        if (t == 1) {
            --x; --y;
            vector<int> new_creature(n);
            for (int j = 0; j < n; ++j) {
                new_creature[j] = max(creatures[x][j], creatures[y][j]);
            }
            new_creatures.push_back(new_creature);
            creatures.push_back(new_creature);
            next_creature_id++;
        } else if (t == 2) {
            --x; --y;
            vector<int> new_creature(n);
            for (int j = 0; j < n; ++j) {
                new_creature[j] = min(creatures[x][j], creatures[y][j]);
            }
            new_creatures.push_back(new_creature);
            creatures.push_back(new_creature);
            next_creature_id++;
        } else {
            --x; --y;
            cout << creatures[x][y - 1] << endl;
        }
    }

    return 0;
}
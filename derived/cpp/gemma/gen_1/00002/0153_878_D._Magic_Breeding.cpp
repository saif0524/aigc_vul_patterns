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
    vector<bool> used_ids(k + 1, false);
    for (int i = 0; i < k; ++i) {
        used_ids[i + 1] = true;
    }

    int next_id = k + 1;

    for (int i = 0; i < q; ++i) {
        int t, x, y;
        cin >> t >> x >> y;

        if (t == 1) {
            vector<int> new_creature(n);
            for (int j = 0; j < n; ++j) {
                new_creature[j] = max(creatures[x - 1][j], creatures[y - 1][j]);
            }
            new_creatures.push_back(new_creature);
            
            int new_creature_id = next_id++;
            used_ids[new_creature_id] = true;
            creatures.push_back(new_creature);

        } else if (t == 2) {
            vector<int> new_creature(n);
            for (int j = 0; j < n; ++j) {
                new_creature[j] = min(creatures[x - 1][j], creatures[y - 1][j]);
            }
            new_creatures.push_back(new_creature);
            
            int new_creature_id = next_id++;
            used_ids[new_creature_id] = true;
            creatures.push_back(new_creature);
        } else {
            
            if (x <= k){
                cout << creatures[x - 1][y - 1] << endl;
            } else {
                int creature_index = x - 1;
                cout << new_creatures[creature_index - k][y-1] << endl;
            }
           
        }
    }

    return 0;
}
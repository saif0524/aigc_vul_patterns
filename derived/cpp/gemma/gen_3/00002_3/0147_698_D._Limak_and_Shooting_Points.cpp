#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    vector<pair<int, int>> stones(k);
    for (int i = 0; i < k; ++i) {
        cin >> stones[i].first >> stones[i].second;
    }

    vector<pair<int, int>> monsters(n);
    for (int i = 0; i < n; ++i) {
        cin >> monsters[i].first >> monsters[i].second;
    }

    int afraid_monsters = 0;
    for (int i = 0; i < n; ++i) {
        bool can_hit = false;
        for (int j = 0; j < k; ++j) {
            int dx = monsters[i].first - stones[j].first;
            int dy = monsters[i].second - stones[j].second;

            if (dx == 0 && dy == 0) continue;

            bool blocked = false;
            for (int l = 0; l < n; ++l) {
                if (l == i) continue;
                int dx2 = monsters[l].first - stones[j].first;
                int dy2 = monsters[l].second - stones[j].second;

                if (dx == 0 && dy == 0) continue;

                if (dx2 == 0 && dy2 == 0) continue;

                if (dx * dy2 == dy * dx2 && dx * dx2 >= 0 && dy * dy2 >= 0) {
                    if (abs(dx) > abs(dx2) || (abs(dx) == abs(dx2) && abs(dy) > abs(dy2))) {
                        blocked = true;
                        break;
                    }
                }
            }

            if (!blocked) {
                can_hit = true;
                break;
            }
        }
        if (can_hit) {
            afraid_monsters++;
        }
    }

    cout << afraid_monsters << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> s(H);
    for (int i = 0; i < H; i++) {
        cin >> s[i];
    }

    vector<pair<int, int>> coins;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (s[i][j] == '#') {
                coins.emplace_back(i, j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < coins.size(); i++) {
        for (int j = i + 1; j < coins.size(); j++) {
            int dist_ij = abs(coins[i].first - coins[j].first) + abs(coins[i].second - coins[j].second);
            set<pair<int, int>> used;
            used.insert(coins[i]);
            used.insert(coins[j]);
            for (int k = j + 1; k < coins.size(); k++) {
                if (used.find(coins[k]) != used.end()) continue;
                int dist_ik = abs(coins[i].first - coins[k].first) + abs(coins[i].second - coins[k].second);
                int dist_jk = abs(coins[j].first - coins[k].first) + abs(coins[j].second - coins[k].second);
                if (dist_ij == dist_ik && dist_ij == dist_jk) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}